#ifndef PLAYER_STRATEGY_BUILDER_H
#define PLAYER_STRATEGY_BUILDER_H
#include "PlayerStrategy.h"
#include "PlayerStrategyBuilder.h"

class PlayerStrategyBuilder {
public:
	virtual void buildDiceRollingStrategy() = 0;
	virtual void buildDiceResolvingStrategy() = 0;
	virtual void buildMovingStrategy() = 0;
	virtual void buildCardBuyingStrategy() = 0;
	void constructPlayerStrategy();
	PlayerStrategy *getResult();
protected:
	PlayerStrategy *strategy;
};
#endif
