#include "ModeratePlayerStrategyBuilder.h"

void ModeratePlayerStrategyBuilder::buildDiceRollingStrategy() {
	this->strategy->setDiceRollingStrategy(new ModerateDiceRollingStrategy);
}

void ModeratePlayerStrategyBuilder::buildDiceResolvingStrategy() {
	this->strategy->setDiceResolvingStrategy(new ModerateDiceResolvingStrategy);
}

void ModeratePlayerStrategyBuilder::buildMovingStrategy() {
	this->strategy->setMovingStrategy(new ModerateMovingStrategy);
}

void ModeratePlayerStrategyBuilder::buildCardBuyingStrategy() {
	this->strategy->setBuyingCardsStrategy(new ModerateBuyingCardsStrategy);
}
