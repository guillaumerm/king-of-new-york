#ifndef MODERATE_BUYING_CARDS_STRATEGY_H
#define MODERATE_BUYING_CARDS_STRATEGY_H
#include "BuyingCardsStrategy.h"
class ModerateBuyingCardsStrategy: public BuyingCardsStrategy {
public:
	void execute(Player & player, vector<GameCard*> cardsAvailable, Deck<GameCard*>* deckOfGameCards);
};
#endif