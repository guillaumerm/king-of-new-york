#ifndef INTERACTIVE_PLAYER_STRATEGY_BUILDER_H
#define INTERACTIVE_PLAYER_STRATEGY_BUILDER_H
#include "PlayerStrategyBuilder.h"
class InteractivePlayerStrategyBuilder : public PlayerStrategyBuilder {
public:
	virtual void buildDiceRollingStrategy();
	virtual void buildDiceResolvingStrategy();
	virtual void buildMovingStrategy();
	virtual void buildCardBuyingStrategy();
};
#endif
