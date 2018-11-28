#include "AggresivePlayerStrategyBuilder.h"
#include "AggresiveDiceRollingStrategy.h"
#include "AggresiveDiceResolvingStrategy.h"
#include "AggresiveMovingStrategy.h"
#include "AggresiveBuyingCardsStrategy.h"


void AggresivePlayerStrategyBuilder::buildDiceRollingStrategy() {
	this->strategy->setDiceRollingStrategy(new AggresiveDiceRollingStrategy());
}

void AggresivePlayerStrategyBuilder::buildDiceResolvingStrategy() {
	this->strategy->setDiceResolvingStrategy(new AggresiveDiceResolvingStrategy());
}

void AggresivePlayerStrategyBuilder::buildMovingStrategy() {
	this->strategy->setMovingStrategy(new AggresiveMovingStrategy());
}

void AggresivePlayerStrategyBuilder::buildCardBuyingStrategy() {
	this->strategy->setBuyingCardsStrategy(new AggresiveBuyingCardsStrategy());
}