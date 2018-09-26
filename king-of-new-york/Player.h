#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "MonsterCard.h"
#include "GameCard.h"

using namespace std;
class Player {
public:
	Player(MonsterCard* monsterCard, int energyCubes);
	void RollDice(string dice);
	void ResolveDice();
	void Move();
	void BuyCards();
	int getVictoryPoints() const;
	int getLifePoints() const;
	int addVictoryPoints(int victoryPoints);
	int addLifePoints(int lifePoints);
	int removeVictoryPoints(int victoryPoints);
	int removeLifePoints(int lifePoints);
private:
	MonsterCard* monsterCard;
	int energyCubes;
	GameCard** gameCards;
};
#endif
