#ifndef MODERATE_MOVING_STRATEGY_H
#define MODERATE_MOVING_STRATEGY_H
#include "MovingStrategy.h"

class ModerateMovingStrategy: public MovingStrategy {
public:
	void execute(Player *player, GameMap *map);
};
#endif
