#ifndef DICE_ROLL_STRATEGY_H
#define DICE_ROLL_STRATEGY_H
#include "Player.h"

using namespace std;

class Player;

class DiceRollingStrategy {
public:
	virtual void execute(Player &player, int numberOfDice) = 0;
};
#endif