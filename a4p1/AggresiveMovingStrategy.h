#ifndef AGGRESIVE_MOVING_STRATEGY_H
#define AGGRESIVE_MOVING_STRATEGY_H
#include "MovingStrategy.h"

/**
 * @brief A concrete class of MovingStrategy which is scripted to move only when necessary. If no one is in Manhatten he moves to the region, else the Player only moves to the next available borough.
 */
class AggresiveMovingStrategy: public MovingStrategy {
public:
	/**
	 * Executes the specific defined MovingStrategy. If no one is in Manhatten he moves to the region, else the Player only moves to the next available borough.
	 * @param player pointer to the player which is moving
	 * @param map game board on which the player is currently located
	 */
	void execute(Player *player, GameMap *map);
};
#endif
