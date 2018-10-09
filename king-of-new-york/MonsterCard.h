#ifndef MONSTER_CARD_H
#define MONSTER_CARD_H

#include <string.h>
#include "Card.h"

class MonsterCard: public Card {
public:
	MonsterCard();
	MonsterCard(std::string name, std::string description);
	MonsterCard(std::string name, std::string description, int lifePoints, int victoryPoints);
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
