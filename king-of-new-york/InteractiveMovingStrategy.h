#ifndef INTERACTIVE_MOVING_STRATEGY_H
#define INTERACTIVE_MOVING_STRATEGY_H
#include "MovingStrategy.h"
#include "Util.h"

/**
 * @brief A concrete class of MovingStrategy which is interactively interacts with the player to make choices where to move.
 */
class InteractiveMovingStrategy :public MovingStrategy {
public:

	/**
	 * Executes the specific defined MovingStrategy.
	 * @param player pointer to the player which is moving
	 * @param map game board on which the player is currently located
	 */
	void execute(Player *player, GameMap *map);
};
#endif
