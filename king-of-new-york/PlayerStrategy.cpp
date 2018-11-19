#include "PlayerStrategy.h"

void PlayerStrategy::setDiceRollingStrategy(DiceRollingStrategy *diceRollingStrategy) {
	this->diceRollingStrategy = diceRollingStrategy;
}

void PlayerStrategy::setDiceResolvingStrategy(DiceResolvingStrategy * diceResolvingStrategy) {
	this->diceResolvingStrategy = diceResolvingStrategy;
}

void PlayerStrategy::setMovingStrategy(MovingStrategy * movingStrategy) {
	this->movingStrategy = movingStrategy;
}

void PlayerStrategy::setBuyingCardsStrategy(BuyingCardsStrategy * buyingCardsStrategy) {
	this->buyingCardStrategy = buyingCardsStrategy;
}

void PlayerStrategy::executeRollDicePhase(Player & player, int numberOfDice)
{
	this->diceRollingStrategy->execute(player, numberOfDice);
}

void PlayerStrategy::executeMovePhase(Player * player, GameMap * map)
{
	this->movingStrategy->execute(player, map);
}

void PlayerStrategy::executeResolveDicePhase(Player & player)
{
	this->diceResolvingStrategy->execute(player);
}

void PlayerStrategy::executeBuyCardsPhase(Player & player, vector<GameCard*> *cardsAvailable, Deck<GameCard*>* deckOfCards)
{
	this->buyingCardStrategy->execute(player, cardsAvailable, deckOfCards);
}

PlayerStrategy::~PlayerStrategy() {
	delete this->diceRollingStrategy;
	this->diceRollingStrategy = NULL;
	delete this->diceResolvingStrategy;
	this->diceResolvingStrategy = NULL;
	delete this->movingStrategy;
	this->movingStrategy = NULL;
	delete this->buyingCardStrategy;
	this->buyingCardStrategy = NULL;
}
