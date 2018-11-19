#ifndef PLAYER_STRATEGY_DIRECTOR_H
#define PLAYER_STRATEGY_DIRECTOR_H
#include "PlayerStrategyBuilder.h"

/**
 * @brief A class which regroups the behavior/action a PlayerStrategyBuilder director will require to construct the appropriate PlayerStrategy.
 */
class PlayerStrategyDirector {
public:

	/**
	 * Sets the current PlayerStrategyBuilder
	 * @param playerStrategyBuilder A pointer to a PlayerStrategyBuilder
	 */
	void setPlayerStrategyBuilder(PlayerStrategyBuilder* playerStrategyBuilder);

	/**
	 * Get the contructed PlayserStrategy
	 * @return a PlayerStrategy of the builders type
	 */
	PlayerStrategy*  getPlayerStrategy();

	/**
	 * Constrcuts the PlayserStrategy using a PlayserStrategyBuilder
	 */
	void constructPlayerStrategy();
private:
	PlayerStrategyBuilder* playerStrategyBuilder; /**< PlayerStrategyBuilder used to construct PlayerStrategy */
};
#endif
