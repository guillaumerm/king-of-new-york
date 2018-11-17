#include "PlayerStrategyBuilder.h"

void PlayerStrategyBuilder::constructPlayerStrategy()
{
	this->strategy = new PlayerStrategy();
}

PlayerStrategy * PlayerStrategyBuilder::getResult()
{
	return this->strategy;
}
