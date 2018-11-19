#ifndef MODERATE_BUYING_CARDS_STRATEGY_H
#define MODERATE_BUYING_CARDS_STRATEGY_H
#include "BuyingCardsStrategy.h"
/**
 * @brief A concrete BuyingCardsStrategy that a scripted player calls when he is executing its buying cards phase. Player aims at buying KeepCard (that is powerups).
 */
class ModerateBuyingCardsStrategy: public BuyingCardsStrategy {
public:

	/**
	 * Executes the specific implemented BuyingCardsStrategy. Aims at buying KeepCard (that is powerups).
	 * @param player reference to the player which is rolling
	 * @param cardsAvailable cards currently available to buy.
	 * @param deckOfGameCards deck of game cards
	 */
	void execute(Player & player, vector<GameCard*> *cardsAvailable, Deck<GameCard*>* deckOfGameCards);
};
#endif