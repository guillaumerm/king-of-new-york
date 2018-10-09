#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "MonsterCard.h"
#include "GameCard.h"
#include "DiceRollingFacility.h"
#include "EnergyCube.h"
#include "Token.h"

using namespace std;
class Player {
public:
	Player(MonsterCard* monsterCard, EnergyCube energyCubes);
	const DiceRoll* rollDice(int numberDice);
	const DiceRoll* resolveDice(bool resolution[]);
	void move();
	void buyCards(GameCard* cards, int numCardsBought);
	bool isDead();
	bool won();
	int getVictoryPoints() const;
	int getLifePoints() const;
	void addVictoryPoints(int victoryPoints);
	void addLifePoints(int lifePoints);
	void removeVictoryPoints(int victoryPoints);
	void removeLifePoints(int lifePoints);
private:
	DiceRollingFacility* diceRollingFacility;
	MonsterCard* monsterCard;
	EnergyCube energyCubes;
	vector<GameCard*> gameCards;
	vector<Token*> tokens;
};
#endif
