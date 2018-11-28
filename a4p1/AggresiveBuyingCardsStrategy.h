#ifndef AGGRESIVE_BUYING__CARDS_STRATEGY_H
#define AGGRESIVE_BUYING__CARDS_STRATEGY_H
#include "BuyingCardsStrategy.h"
/**
 * @brief A concrete BuyingCardsStrategy that a scripted player calls when he is executing its buying cards phase. Player disregard buying cards.
 */
class AggresiveBuyingCardsStrategy: public BuyingCardsStrategy {
public:
	/**
	 * Executes the specific implemented BuyingCardsStrategy. Player disregard buying cards.
	 * @param player reference to the player which is rolling
	 * @param cardsAvailable cards currently available to buy.
	 * @param deckOfGameCards deck of game cards
	 */
	void execute(Player & player, vector<GameCard*> *cardsAvailable, Deck<GameCard*>* deckOfGameCards);
};
#endif
