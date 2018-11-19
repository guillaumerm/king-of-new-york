#ifndef PLAYER_STRATEGY_BUILDER_H
#define PLAYER_STRATEGY_BUILDER_H
#include "PlayerStrategy.h"
#include "PlayerStrategyBuilder.h"
/**
 * @brief An interface which regroups the behavior/action a PlayerStrategyBuilder.
 */
class PlayerStrategyBuilder {
public:

	/**
	 * Builds the DiceRollingStrategy
	 */
	virtual void buildDiceRollingStrategy() = 0;

	/**
	 * Builds the DiceResolvingStrategy
	 */
	virtual void buildDiceResolvingStrategy() = 0;

	/**
	 * Builds the MovingStrategy
	 */
	virtual void buildMovingStrategy() = 0;

	/**
	 * Builds the CardBuyingStrategy
	 */
	virtual void buildCardBuyingStrategy() = 0;

	/**
	 * Constructs a PlayerStrategy the related sub-strategies
	 */
	void constructPlayerStrategy();

	/**
	 * Obtained the last built PlayerStrategy
	 * @return a PlayerStrategy
	 */
	PlayerStrategy *getResult();
protected:
	PlayerStrategy *strategy; /** < Last PlayerStrategy that has been built */
};
#endif
