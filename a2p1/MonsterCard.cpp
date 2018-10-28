#include <string.h>

#include "MonsterCard.h"
using namespace std;

const int STARTING_LIFE_POINTS = 10;
const int MIN_LIFE_POINTS = 0;
const int MAX_LIFE_POINTS = 10;

const int STARTING_VICTORY_POINTS = 0;
const int MAX_VICTORY_POINTS = 20;
const int MIN_VICTORY_POINTS = 0;
MonsterCard::MonsterCard() : MonsterCard("", "") {};
MonsterCard::MonsterCard(string name, string description) : MonsterCard(name, description, STARTING_LIFE_POINTS, STARTING_VICTORY_POINTS) {};

MonsterCard::MonsterCard(string name, string description, int lifePoints, int victoryPoints) : Card(name, description) {
	if (!(lifePoints >= MIN_LIFE_POINTS && lifePoints <= MAX_LIFE_POINTS)) {
		throw new domain_error("Invalid value for Life Points");
		exit(1);
	}
	else
	{
		this->lifePoints = lifePoints;
	}

	if (!(victoryPoints >= MIN_VICTORY_POINTS && victoryPoints <= MAX_VICTORY_POINTS))
	{
		throw new domain_error("Invalid value for Victory Points");
		exit(1);
	}
	else 
	{
		this->victoryPoints = victoryPoints;
	}
}

void MonsterCard::addLifePoints(int lifePoints) {
	if (this->lifePoints + lifePoints <= MAX_LIFE_POINTS)
		this->lifePoints += lifePoints;
}

void MonsterCard::removeLifePoints(int lifePoints) {
	if (this->lifePoints - lifePoints >= MIN_LIFE_POINTS)
		this->lifePoints -= lifePoints;
}

void MonsterCard::addVictoryPoints(int victoryPoints) {
	if (this->victoryPoints + victoryPoints <= MAX_VICTORY_POINTS)
		this->victoryPoints += victoryPoints;
}

void MonsterCard::removeVictoryPoints(int victoryPoints) {
	if (this->victoryPoints - victoryPoints >= MIN_VICTORY_POINTS)
		this->victoryPoints -= victoryPoints;
}

int MonsterCard::getLifePoint() const {
	return this->lifePoints;
}

int MonsterCard::getVictoryPoint() const {
	return this->victoryPoints;
}


ostream& operator<<(ostream &strm, const MonsterCard &card) {
	return strm << "MonsterCard (name:" << card.name << "; description:" << card.description << "; lifePoints:" << card.lifePoints << "; victoryPoints:" << card.victoryPoints <<")";
}