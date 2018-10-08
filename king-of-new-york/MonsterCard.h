#ifndef MONSTER_CARD_H
#define MONSTER_CARD_H

#include <string>
#include "Card.h"

using namespace std;

class MonsterCard: public Card {
public:
	MonsterCard();
	MonsterCard(string name, string description);
	MonsterCard(string name, string description, int lifePoints, int victoryPoints);
	int getLifePoint() const;
	int getVictoryPoint() const;
	void removeLifePoints(int lifePoints);
	void addLifePoints(int lifePoints);
	void addVictoryPoints(int victoryPoints);
	void removeVictoryPoints(int victoryPoints);
private:
	int lifePoints;
	int victoryPoints;
	friend ostream& operator<<(ostream& strm, const MonsterCard&);
};
#endif
