#ifndef AGGRESIVE_MOVING_STRATEGY_H
#define AGGRESIVE_MOVING_STRATEGY_H
#include "MovingStrategy.h"

class AggresiveMovingStrategy: public MovingStrategy {
public:
	void execute(Player *player, GameMap *map);
};
#endif
