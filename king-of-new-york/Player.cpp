#include <unordered_map>
#include "Player.h"

Player::Player() : Player(NULL, 0, "", PlayerStateMachine::PlayerState::Idle) {

}


Player::Player(MonsterCard* monsterCard) : Player(monsterCard, 0, "", PlayerStateMachine::PlayerState::Idle) { }

Player::Player(MonsterCard* monsterCard, EnergyCube energyCubes, string startingZone): Player(monsterCard, energyCubes, startingZone, PlayerStateMachine::PlayerState::Idle) {

}


Player::Player(MonsterCard* monsterCard, EnergyCube energyCubes, string startingZone, PlayerStateMachine::PlayerState state) {
	this->monsterCard = monsterCard;
	this->energyCubes = energyCubes;
	this->diceRollingFacility = new DiceRollingFacility();
	this->currentZone = startingZone;
	this->state.setCurrentState(state);
}

Player::~Player() {
	this->monsterCard = nullptr;
	delete diceRollingFacility;
}

void Player::buyCards(GameCard* cards, int numCardsBought) {
	if (!this->state.isBuying()) {
		throw exception("The player cannot buying as he is not in the buying phase.");
		exit(1);
	}

	int cost = 0;
	
	for (int i = 0; i < numCardsBought; i++) {
		cost += cards[i].getCost();
	}

	if ((this->energyCubes - cost) <= 0) {
		throw out_of_range("Cost of bought cards exceeds current amount of energyCubes held by player.");
		exit(1);
	}

	this->energyCubes -= cost;
	for (int i = 0; i < numCardsBought; i++) {
		this->gameCards.push_back(&cards[i]);
	}
	this->state.proceed();
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
}

void Player::removeVictoryPoints(int victoryPoints) {
	this->monsterCard->removeVictoryPoints(victoryPoints);
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

	if (this->isRolling()) {
		this->state.proceed();
	}

	return this->diceRollingFacility->roll(numberDice);
}

const DiceRoll* Player::rollDice(bool diceToKeep[]) {
	this->state.proceed();
	return this->diceRollingFacility->reroll(diceToKeep);
}

const unordered_map<Die::Face, int> Player::resolveDice(unordered_set<Die::Face> order) {
	if (!this->state.isResolving()) {
		throw exception("The player cannot roll has he is not in the resolving phase.");
		exit(1);
	}

	unordered_map<Die::Face, int> resolution;
	const DiceRoll *lastRoll = this->diceRollingFacility->getLastRoll();
	unordered_set<Die::Face>::iterator iter;
	
	for (iter = order.begin(); iter != order.end(); iter++) {
		resolution.insert({ *iter, lastRoll->getSumFace(*iter) });
	}
	this->state.proceed();
	return resolution;
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
}

string Player::getMonster()
{
	return this->monsterCard->getName();
}