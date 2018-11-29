#ifndef INTERACTIVE_PLAYER_STRATEGY_BUILDER_H
#define INTERACTIVE_PLAYER_STRATEGY_BUILDER_H
#include "PlayerStrategyBuilder.h"
#include "InteractiveDiceRollingStrategy.h"
#include "InteractiveDiceResolvingStrategy.h"
#include "InteractiveBuyingCardsStrategy.h"
#include "InteractiveMovingStrategy.h"

/**
 * @brief A concrete PlayerStrategyBuilder which regroups the steps in constructing interactive Player. This kind of Player interactively answer the prompt to play its different phases.
 */
class InteractivePlayerStrategyBuilder : public PlayerStrategyBuilder {
public:
	/**
	 * Builds the DiceRollingStrategy. Interactively ask the user to select rerolls and which dice to keep.
	 */
	void buildDiceRollingStrategy();

	/**
	 * Builds the DiceResolvingStrategy. Interactively ask the user to select the resolve order.
	 */
	void buildDiceResolvingStrategy();

	/**
	 * Builds the MovingStrategy. If no one is in Manhatten he moves to the region, else the is interactively ask the user to select which neighbouring zones he wants to move to.
	 */
	void buildMovingStrategy();

	/**
	 * Builds the CardBuyingStrategy. Interactively ask the user to select the which cards he want to buy if any.
	 */
	void buildCardBuyingStrategy();
};
#endif
