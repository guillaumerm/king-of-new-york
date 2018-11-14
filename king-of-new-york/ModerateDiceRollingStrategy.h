#ifndef MODERATE_DICE_ROLLING_STRATEGY_H
#define MODERATE_DICE_ROLLING_STRATEGY_H
#include "DiceRollingStrategy.h"

class ModerateDiceRollingStrategy: public DiceRollingStrategy {
public:
	void execute(Player &player, int numberOfDice);
};
#endif
