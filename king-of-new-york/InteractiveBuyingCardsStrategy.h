#ifndef INTERACTIVE_BUYING_CARDS_STRATEGY_H
#define INTERACTIVE_BUYING_CARDS_STRATEGY_H
#include "BuyingCardsStrategy.h"
#include "Util.h"

using namespace std;

class InteractiveBuyingCardsStrategy : public BuyingCardsStrategy {
public:
	void execute(Player & player, vector<GameCard*> cardsAvailable, Deck<GameCard*> *deckOfCards);
};
#endif
