#ifndef INTERACTIVE_BUYING_CARDS_STRATEGY_H
#define INTERACTIVE_BUYING_CARDS_STRATEGY_H
#include "Util.h"
#include "BuyingCardsStrategy.h"

using namespace std;

/**
 * @brief A concrete BuyingCardsStrategy that a player calls when he is executing its buying cards phase. Interactively decides which cards to buy.
 */
class InteractiveBuyingCardsStrategy : public BuyingCardsStrategy {
public:
	/**
	 * Executes the specific implemented BuyingCardsStrategy. Interactively decides which cards to buy.
	 * @param player reference to the player which is rolling
	 * @param cardsAvailable cards currently available to buy.
	 * @param deckOfGameCards deck of game cards
	 */
	void execute(Player & player, vector<GameCard*> *cardsAvailable, Deck<GameCard*> *deckOfCards);

private:
	/**
	 * Function which executes dealing new cards available to buy at the cost of two(2) energy cubes
	 * @param player player which is dealing new cards.
	 * @param cardsAvailable cards currently available to buy
	 */
	void dealNewCardsToBuy(Player &player, vector<GameCard*> *cardsAvailable, Deck<GameCard*>* deckOfCards);
};
#endif
