#ifndef MOVE_STRATEGY_H
#define MOVE_STRATEGY_H
#include "Player.h"
#include "GameMap.h"

class Player;
class GameMap;

/**
 * @brief An interface that declare what a MovingStrategy requires to implement. A MovingStrategy is the strategy that a Player calls when he is executing its moving phase.
 */
class MovingStrategy {
public:
	/**
	 * Executes the specific defined MovingStrategy
	 * @param player pointer to the player which is moving
	 * @param map game board on which the player is currently located
	 */
	virtual void execute(Player *player, GameMap *map) = 0;
};
#endif