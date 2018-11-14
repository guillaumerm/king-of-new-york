#ifndef AGGRESIVE_DICE_RESOLVING_STRATEGY_H
#define AGGRESIVE_DICE_RESOLVING_STRATEGY_H
#include "DiceResolvingStrategy.h"
#include "Player.h"

class AggresiveDiceResolvingStrategy : public DiceResolvingStrategy {
public:
	void execute(Player &player);
};
#endif
