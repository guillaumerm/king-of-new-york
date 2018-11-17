#include <unordered_map>
#include "Player.h"

Player::Player() : Player(NULL, 0, "", PlayerStateMachine::PlayerState::Idle, NULL) {

}


Player::Player(MonsterCard* monsterCard, PlayerStrategy* strategy) : Player(monsterCard, 0, "", PlayerStateMachine::PlayerState::Idle, strategy) { }

Player::Player(MonsterCard* monsterCard, EnergyCube energyCubes, string startingZone, PlayerStrategy* strategy): Player(monsterCard, energyCubes, startingZone, PlayerStateMachine::PlayerState::Idle, strategy) {

}


Player::Player(MonsterCard* monsterCard, EnergyCube energyCubes, string startingZone, PlayerStateMachine::PlayerState state, PlayerStrategy* strategy) {
	this->monsterCard = monsterCard;
	this->energyCubes = energyCubes;
	this->diceRollingFacility = new DiceRollingFacility();
	this->currentZone = startingZone;
	this->state.setCurrentState(state);
	this->strategy = strategy;
}

Player::~Player() {
	this->monsterCard = nullptr;
	delete diceRollingFacility;
}

void Player::buyCards(unordered_set<GameCard*> cardsToBeBought) {
	if (!this->state.isBuying()) {
		throw exception("The player cannot buying as he is not in the buying phase.");
		exit(1);
	}

	if(cardsToBeBought.empty()){
		this->endPhase();
		return;
	}

	int cost = 0;
	
	for (auto card: cardsToBeBought) {
		cost += card->getCost();
	}

	if ((this->energyCubes - cost) <= 0) {
		throw out_of_range("Cost of bought cards exceeds current amount of energyCubes held by player.");
		exit(1);
	}

	this->energyCubes -= cost;
	for (auto card : cardsToBeBought) {
		this->gameCards.push_back(card);
	}

	cardsToBeBought.clear();
	dynamic_cast<PhaseSubject*>(this)->notify();
	this->state.proceed();
}

void Player::executeTurn(GameMap* board, vector<GameCard*> cardsAvailable, int numberOfDice, Deck<GameCard*>* deckOfCards) {
	if (this->isIdle()) {
		throw "Not players turn to play";
		return;
	}
	
	if (this->isDead()) {
		throw "Player is dead";
		return;
	}

	while (!this->isIdle()) {
		if (this->isRolling()) {
			this->strategy->executeRollDicePhase(*this, numberOfDice);
		}
		else if (this->isRelsoving()) {
			this->strategy->executeResolveDicePhase(*this);
		}
		else if (this->isMoving()) {
			this->strategy->executeMovePhase(this, board);
		}
		else if (this->isBuying()) {
			this->strategy->executeBuyCardsPhase(*this, cardsAvailable, deckOfCards);
		}
		else {
			throw "Illegal State";
		}
	}
}

unordered_map<Die::Face, int> Player::getLastResolved()
{
	return *this->lastResolved;
}

const DiceRoll* Player::getLastRoll()
{
	return this->diceRollingFacility->getLastRoll();
}

vector<GameCard*> Player::getHand()
{
	return this->gameCards;
}

void Player::removeEnergyCubes(int amount) {
	int diff = this->energyCubes - amount;
	this->energyCubes = diff < 0 ? 0 : diff;
}

int Player::getEnergyCubes() const{
	return this->energyCubes;
}

void Player::addEnergyCubes(int amount) {
	this->energyCubes += amount;
}

int Player::getLifePoints() const {
	return this->monsterCard->getLifePoint();
}

int Player::getVictoryPoints() const {
	return this->monsterCard->getVictoryPoint();
}

void Player::addLifePoints(int lifePoints) {
	this->monsterCard->addLifePoints(lifePoints);
}

void Player::addVictoryPoints(int victoryPoints) {
	this->monsterCard->addVictoryPoints(victoryPoints);
	dynamic_cast<GameStatisticSubject*>(this)->notify(this->monsterCard->getName(), this->currentZone, this->monsterCard->getVictoryPoint());
}

void Player::removeVictoryPoints(int victoryPoints) {
	this->monsterCard->removeVictoryPoints(victoryPoints);
	dynamic_cast<GameStatisticSubject*>(this)->notify(this->monsterCard->getName(), this->currentZone, this->monsterCard->getVictoryPoint());
}

void Player::removeLifePoints(int lifePoints) {
	this->monsterCard->removeLifePoints(lifePoints);
}

bool Player::isRolling() const {
	return this->state.isRolling();
}

bool Player::isMoving() const {
	return this->state.isMoving();
}

bool Player::isRelsoving() const {
	return this->state.isResolving();
}

bool Player::isBuying() const {
	return this->state.isBuying();
}

bool Player::isDead(){
	return this->monsterCard->getLifePoint() <= 0;
}

bool Player::isIdle() {
	return this->state.isIdle();
}

void Player::startTurn() {
	this->state.initTurn();
}

void Player::endTurn() {
	this->state.endTurn();
}

void Player::endPhase() {
	this->state.next();
}

const DiceRoll* Player::rollDice(int numberDice) {
	if (!this->state.isIdle() && !this->state.isRolling()) {
		throw exception("The player cannot roll has he is not in the rolling phase.");
		exit(1);
	}
	const DiceRoll *roll = this->diceRollingFacility->roll(numberDice);

	if (this->isRolling()) {
		dynamic_cast<PhaseSubject*>(this)->notify();
		this->state.proceed();
	}

	return roll;
}

const DiceRoll* Player::rollDice(bool diceToKeep[]) {
	dynamic_cast<PhaseSubject*>(this)->notify();
	this->state.proceed();
	return this->diceRollingFacility->reroll(diceToKeep);
}

const unordered_map<Die::Face, int> Player::resolveDice(unordered_set<Die::Face> order) {
	delete this->lastResolved;
	this->lastResolved = NULL;

	if (!this->state.isResolving()) {
		throw exception("The player cannot roll has he is not in the resolving phase.");
		exit(1);
	}

	this->lastResolved = new unordered_map<Die::Face, int>();
	const DiceRoll *lastRoll = this->diceRollingFacility->getLastRoll();
	unordered_set<Die::Face>::iterator iter;
	
	for (iter = order.begin(); iter != order.end(); iter++) {
		this->lastResolved->insert({ *iter, lastRoll->getSumFace(*iter) });
	}

	this->state.proceed();
	this->lastResolved = this->lastResolved;
	dynamic_cast<PhaseSubject*>(this)->notify();
	return *this->lastResolved;
}

void Player::move(GameMap *map, string nameDestinationZone) {
	if (!this->state.isMoving()) {
		throw exception("The player cannot move has he is not in the moving phase.");
		exit(1);
	}

	if (map->adjancent(this->currentZone, nameDestinationZone) && map->getZoneByName(nameDestinationZone)->isNotFull()) {
		this->state.proceed();
		map->movePlayer(this, this->currentZone, nameDestinationZone);
		this->setCurrentZone(nameDestinationZone);
		dynamic_cast<PhaseSubject*>(this)->notify();
	}
	else {
		throw out_of_range("Cannot move to a none adjacent zone");
		exit(1);
	};
}

string Player::getCurrentZone() const {
	return this->currentZone;
}

void Player::setCurrentZone(string newCurrentZone) {
	this->currentZone = newCurrentZone;
	dynamic_cast<GameStatisticSubject*>(this)->notify(this->monsterCard->getName(), this->currentZone, this->monsterCard->getVictoryPoint());
}

void Player::setPlayerStrategy(PlayerStrategy * strategy) {
	delete this->strategy;
	this->strategy = strategy;
}

string Player::getMonster()
{
	return this->monsterCard->getName();
}