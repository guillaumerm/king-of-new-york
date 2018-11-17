#ifndef AGGRESIVE_BUYING__CARDS_STRATEGY_H
#define AGGRESIVE_BUYING__CARDS_STRATEGY_H
#include "BuyingCardsStrategy.h"

class AggresiveBuyingCardsStrategy: public BuyingCardsStrategy {
public:
	void execute(Player & player, vector<GameCard*> cardsAvailable, Deck<GameCard*>* deckOfGameCards);
};
#endif
