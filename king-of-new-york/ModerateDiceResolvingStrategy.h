#ifndef MODERATE_DICE_RESOLVING_STRATEGY_H
#define MODERATE_DICE_RESOLVING_STRATEGY_H
#include "DiceResolvingStrategy.h"

class ModerateDiceResolvingStrategy:public DiceResolvingStrategy {
public:
	void execute(Player &player);
};
#endif
