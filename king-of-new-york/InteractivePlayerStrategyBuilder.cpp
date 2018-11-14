#include "InteractivePlayerStrategyBuilder.h"
#include "InteractiveDiceRollingStrategy.h"
#include "InteractiveDiceResolvingStrategy.h"
#include "InteractiveBuyingCardsStrategy.h"
#include "InteractiveMovingStrategy.h"

void InteractivePlayerStrategyBuilder::buildDiceRollingStrategy() {
	this->strategy->setDiceRollingStrategy(new InteractiveDiceRollingStrategy);
}

void InteractivePlayerStrategyBuilder::buildDiceResolvingStrategy() {
	this->strategy->setDiceResolvingStrategy(new InteractiveDiceResolvingStrategy);
}

void InteractivePlayerStrategyBuilder::buildMovingStrategy() {
	this->strategy->setMovingStrategy(new InteractiveMovingStrategy);
}

void InteractivePlayerStrategyBuilder::buildCardBuyingStrategy() {
	this->strategy->setBuyingCardsStrategy(new InteractiveBuyingCardsStrategy);
}
