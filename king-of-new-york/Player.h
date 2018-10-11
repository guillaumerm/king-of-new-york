#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "GameMap.h"
#include "MonsterCard.h"
#include "GameCard.h"
#include "DiceRollingFacility.h"
#include "EnergyCube.h"
#include "Token.h"

class GameMap;

using namespace std;
class Player {
public:
	Player();
	Player(MonsterCard* monsterCard, EnergyCube energyCubes, string startingZone);
	const DiceRoll* rollDice(int numberDice);
	const DiceRoll* resolveDice(bool resolution[]);
	void move(GameMap *, string);
	void buyCards(GameCard* cards, int numCardsBought);
	bool isDead();
	bool won();
	int getVictoryPoints() const;
	int getLifePoints() const;
	void addVictoryPoints(int victoryPoints);
	void addLifePoints(int lifePoints);
	void removeVictoryPoints(int victoryPoints);
	void removeLifePoints(int lifePoints);
	string getCurrentZone() const;
private:
	DiceRollingFacility* diceRollingFacility;
	MonsterCard* monsterCard;
	EnergyCube energyCubes;
	vector<GameCard*> gameCards;
	vector<Token*> tokens;
	string currentZone;
	void setCurrentZone(string);
};
#endif
