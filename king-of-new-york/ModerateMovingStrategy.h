#ifndef MODERATE_MOVING_STRATEGY_H
#define MODERATE_MOVING_STRATEGY_H
#include "MovingStrategy.h"
/**
 * @brief A concrete class of MovingStrategy which is scripted to move only when necessary.
 */
class ModerateMovingStrategy: public MovingStrategy {
public:
	/**
	 * Executes the specific defined MovingStrategy. Move only when necessary.
	 * @param player pointer to the player which is moving
	 * @param map game board on which the player is currently located
	 */
	void execute(Player *player, GameMap *map);
};
#endif
