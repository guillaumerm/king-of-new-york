#include "ModerateBuyingCardsStrategy.h"

void ModerateBuyingCardsStrategy::execute(Player & player, vector<GameCard*> *cardsAvailable, Deck<GameCard*>* deckOfGameCards) {
	unordered_set<GameCard*> cardsToBeBought;
	int cost = 0;
	vector<GameCard*>::iterator card = cardsAvailable->begin();

	while(card != cardsAvailable->end() && cost + (*card)->getCost() < player.getEnergyCubes()) {
		GameCard *currentCard = *card;
		KeepCard *keepCard = dynamic_cast<KeepCard*>(currentCard);
		// Card is not of type KeepCard (that is power ups) check next cards
		if (!keepCard) {
			continue;
		}

		if (cost + keepCard->getCost() <= player.getEnergyCubes()) {
			cost += keepCard->getCost();
			cardsToBeBought.emplace(keepCard);
		}
	}

	for (auto card : cardsToBeBought) {
		auto cardToRemove = std::find(cardsAvailable->begin(), cardsAvailable->end(), card);
		if (cardToRemove != cardsAvailable->end()) {
			cardsAvailable->erase(cardToRemove);
		}
	}

	player.buyCards(cardsToBeBought);
}
