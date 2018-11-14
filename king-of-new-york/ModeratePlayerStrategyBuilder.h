#ifndef MODERATE_PLAYER_STRATEGY_BUILDER_H
#define MODERATE_PLAYER_STRATEGY_BUILDER_H
#include "PlayerStrategyBuilder.h"

class ModeratePlayerStrategyBuilder :public PlayerStrategyBuilder {
public:
	virtual void buildDiceRollingStrategy();
	virtual void buildDiceResolvingStrategy();
	virtual void buildMovingStrategy();
	virtual void buildCardBuyingStrategy();
};
#endif
