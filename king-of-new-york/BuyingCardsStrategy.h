#ifndef BUYING_CARDS_STRATEGY_H
#define BUYING_CARDS_STRATEGY_H
#include "Player.h"
#include "GameCard.h"
#include "Deck.h"

using namespace std;

class Player;

class BuyingCardsStrategy {
public:
	virtual void execute(Player &player, vector<GameCard*> cardsAvailable, Deck<GameCard*>* deckOfGameCards) = 0;
};
#endif
