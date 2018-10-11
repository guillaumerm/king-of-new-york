#include <string>
#include "Player.h"

using namespace std;

Player::Player() : Player(NULL, 0, "") {

}

Player::Player(MonsterCard* monsterCard, EnergyCube energyCubes, string startingZone) {
	this->monsterCard = monsterCard;
	this->energyCubes = energyCubes;
	this->diceRollingFacility = new DiceRollingFacility();
	this->currentZone = startingZone;
}

void Player::buyCards(GameCard* cards, int numCardsBought) {
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

bool Player::isDead(){
	return this->monsterCard->getLifePoint() <= 0;
}

bool Player::won() {
	return this->monsterCard->getVictoryPoint() >= 20;
}

const DiceRoll* Player::rollDice(int numberDice) {
	return this->diceRollingFacility->roll(numberDice);
}

const DiceRoll* Player::resolveDice(bool resolution[]) {
	return this->diceRollingFacility->resolve(resolution);
}

void Player::move(GameMap *map, string nameDestinationZone) {
	if (map->adjancent(this->currentZone, nameDestinationZone)) {
		map->movePlayer(this, this->currentZone, nameDestinationZone);
		this->setCurrentZone(nameDestinationZone);
	}
	else {
		throw out_of_range("Cannot move to a none adjacent zone");
	};
}

string Player::getCurrentZone() const {
	return this->currentZone;
}

void Player::setCurrentZone(string newCurrentZone) {
	this->currentZone = newCurrentZone;
}