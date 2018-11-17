#ifndef DICE_RESOLVING_STRATEGY_H
#define DICE_RESOLVING_STRATEGY_H
#include "Player.h"

using namespace std;

class Player;

class DiceResolvingStrategy {
public:
	virtual void execute(Player &player) = 0;
};
#endif
