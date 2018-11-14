#include "PlayerStrategyDirector.h"

void PlayerStrategyDirector::setPlayerStrategyBuilder(PlayerStrategyBuilder * playerStrategyBuilder) {
	this->playerStrategyBuilder = playerStrategyBuilder;
}

PlayerStrategy * PlayerStrategyDirector::getPlayerStrategy()
{
	return this->playerStrategyBuilder->getResult();
}

void PlayerStrategyDirector::constructPlayerStrategy() {
	this->playerStrategyBuilder->constructPlayerStrategy();
	this->playerStrategyBuilder->buildDiceRollingStrategy();
	this->playerStrategyBuilder->buildDiceResolvingStrategy();
	this->playerStrategyBuilder->buildCardBuyingStrategy();
	this->playerStrategyBuilder->buildMovingStrategy();
}
