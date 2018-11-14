#ifndef INTERACTIVE_DICE_ROLLING_STRATEGY_H
#define INTERACTIVE_DICE_ROLLING_STRATEGY_H
#include "DiceRollingStrategy.h"
class InteractiveDiceRollingStrategy :public DiceRollingStrategy {
public:
	void execute(Player &player, int numberOfDice);
};
#endif
