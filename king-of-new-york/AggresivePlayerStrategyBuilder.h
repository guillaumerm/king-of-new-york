#ifndef AGGRESIVE_PLAYER_STRATEGY_BUILDER_H
#define AGGRESIVE_PLAYER_STRATEGY_BUILDER_H
#include "PlayerStrategyBuilder.h"

#include "AggresiveDiceRollingStrategy.h"
#include "AggresiveDiceResolvingStrategy.h"
#include "AggresiveMovingStrategy.h"
#include "AggresiveBuyingCardsStrategy.h"
/**
 * @brief A concrete PlayerStrategyBuilder which regroups the steps in constructing a scripted aggresive Player. This kind of Player aims at causing damage.
 */
class AggresivePlayerStrategyBuilder: public PlayerStrategyBuilder {
public:
	/**
	 * Builds the DiceRollingStrategy. Aims at rolling Destruction(Die::Face::D) and Attack(Die::Face::A).
	 */
	void buildDiceRollingStrategy();

	/**
	 * Builds the DiceResolvingStrategy. Aims at playing Destruction(Die::Face::D) and Attack(Die::Face::A) first.
	 */
	void buildDiceResolvingStrategy();

	/**
	 * Builds the MovingStrategy. If no one is in Manhatten he moves to the region, else the Player only moves to the next available borough.
	 */
	void buildMovingStrategy();

	/**
	 * Builds the CardBuyingStrategy. This player disregard buying cards.
	 */
	void buildCardBuyingStrategy();
};
#endif
