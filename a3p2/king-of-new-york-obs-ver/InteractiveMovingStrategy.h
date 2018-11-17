#ifndef INTERACTIVE_MOVING_STRATEGY_H
#define INTERACTIVE_MOVING_STRATEGY_H
#include "MovingStrategy.h"
class InteractiveMovingStrategy :public MovingStrategy {
public:
	void execute(Player *player, GameMap *map);
};
#endif
