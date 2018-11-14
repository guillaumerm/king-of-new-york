#ifndef AGGRESIVE_PLAYER_STRATEGY_BUILDER_H
#define AGGRESIVE_PLAYER_STRATEGY_BUILDER_H
#include "PlayerStrategyBuilder.h"

class AggresivePlayerStrategyBuilder: public PlayerStrategyBuilder {
	virtual void buildDiceRollingStrategy();
	virtual void buildDiceResolvingStrategy();
	virtual void buildMovingStrategy();
	virtual void buildCardBuyingStrategy();
};
#endif
