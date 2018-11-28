#ifndef BUYING_CARDS_STRATEGY_H
#define BUYING_CARDS_STRATEGY_H
#include "Player.h"
#include "GameCard.h"
#include "Deck.h"

using namespace std;

class Player;

/**
 * @brief An interface that declare what a BuyingCardsStrategy requires to implement. A BuyingCardsStrategy is the strategy that a Player calls when he is executing its buy cards phase.
 */
class BuyingCardsStrategy {
public:

	/**
	 * Executes the specific defined DiceResolvingStrategy
	 * @param player reference to the player which is rolling
	 * @param cardsAvailable cards currently available to buy.
	 * @param deckOfGameCards deck of game cards
	 */
	virtual void execute(Player &player, vector<GameCard*> *cardsAvailable, Deck<GameCard*>* deckOfGameCards) = 0;
};
#endif
