#ifndef MOVE_STRATEGY_H
#define MOVE_STRATEGY_H
#include "Player.h"
#include "GameMap.h"

class Player;
class GameMap;

class MovingStrategy {
public:
	virtual void execute(Player *player, GameMap *map) = 0;
};
#endif