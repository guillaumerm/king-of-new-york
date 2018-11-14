#include "ModerateBuyingCardsStrategy.h"
#include "KeepCard.h"

void ModerateBuyingCardsStrategy::execute(Player & player, vector<GameCard*> cardsAvailable) {
	unordered_set<GameCard*> cardsToBeBought;
	int cost = 0;
	vector<GameCard*>::iterator card = cardsAvailable.begin();

	while(card != cardsAvailable.end() && cost + (*card)->getCost() < player.getEnergyCubes()) {
		GameCard *currentCard = *card;
		KeepCard *keepCard = dynamic_cast<KeepCard*>(currentCard);
		// Card is not of type KeepCard (that is power ups) check next cards
		if (!keepCard) {
			continue;
		}

		if (cost + keepCard->getCost() <= player.getEnergyCubes()) {
			cost += keepCard->getCost();
			//cardsAvailable.erase(*card);
			cardsToBeBought.emplace(keepCard);
		}
	}

	player.buyCards(cardsToBeBought);
}
