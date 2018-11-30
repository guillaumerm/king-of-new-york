#include "ModerateBuyingCardsStrategy.h"

void ModerateBuyingCardsStrategy::execute(Player & player, vector<GameCard*> *cardsAvailable, Deck<GameCard*>* deckOfGameCards) {
	unordered_set<GameCard*> cardsToBeBought;
	int cost = 0;
	vector<GameCard*>::iterator card = cardsAvailable->begin();

	while(card != cardsAvailable->end() && cost + (*card)->getCost() < player.getEnergyCubes()) {
		GameCard *currentCard = *card;

		if (cost + currentCard->getCost() <= player.getEnergyCubes()) {
			cost += currentCard->getCost();
			cardsToBeBought.emplace(currentCard);
		}
		card++;
	}

	for (int i = 0; i < cardsToBeBought.size(); i++) {
		cardsAvailable->push_back(*deckOfGameCards->deal());
	}

	for (auto card : cardsToBeBought) {
		auto cardToRemove = std::find(cardsAvailable->begin(), cardsAvailable->end(), card);
		if (cardToRemove != cardsAvailable->end()) {
			cardsAvailable->erase(cardToRemove);
		}
	}

	player.buyCards(cardsToBeBought);

	for (auto card : cardsToBeBought) {
		deckOfGameCards->push(card);
	}
	deckOfGameCards->shuffle();
	cardsToBeBought.clear();
}
