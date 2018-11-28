#ifndef MODERATE_PLAYER_STRATEGY_BUILDER_H
#define MODERATE_PLAYER_STRATEGY_BUILDER_H
#include "PlayerStrategyBuilder.h"

/**
 * @brief A concrete PlayerStrategyBuilder which regroups the steps in constructing a scripted moderate Player. This kind of Player aims in gaining victory points and power ups (KeepCards).
 */
class ModeratePlayerStrategyBuilder :public PlayerStrategyBuilder {
public:
	/**
	 * Builds the DiceRollingStrategy. Aims at rolling Energy(Die::Face::E), Heal(Die::Face::H) and Celebrity(Die::Face::C).
	 */
	virtual void buildDiceRollingStrategy();

	/**
	 * Builds the DiceResolvingStrategy. Aims at playing Energy(Die::Face::E), Heal(Die::Face::H) and Celebrity(Die::Face::C) first.
	 */
	virtual void buildDiceResolvingStrategy();

	/**
	 * Builds the MovingStrategy. If no one is in Manhatten he moves to the region, else the Player only moves when necessary.
	 */
	virtual void buildMovingStrategy();

	/**
	 * Builds the CardBuyingStrategy. Only buy KeepCard since this strategy the Player aims at accumulating power ups.
	 */
	virtual void buildCardBuyingStrategy();
};
#endif
