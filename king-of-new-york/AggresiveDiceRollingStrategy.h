#ifndef AGGRESIVE_DICE_ROLL_STRATEGY_H
#define AGGRESIVE_DICE_ROLL_STRATEGY_H
#include "DiceRollingStrategy.h"
#include "Player.h"

class AggresiveDiceRollingStrategy: public DiceRollingStrategy {
public:
	void execute(Player &player, int numberOfDice);
};
#endif
