#include "InteractiveBuyingCardsStrategy.h"

void InteractiveBuyingCardsStrategy::execute(Player & player, vector<GameCard*> *cardsAvailable, Deck<GameCard*> *deckOfCards) {
	cout << "--Cards Available to buy--" << endl;
	
	for (auto iter : *cardsAvailable) {
		cout << *iter << endl;
	}

	if (player.getEnergyCubes() < 1) {
		cout << "You do not have enough energy cubes to buy cards " << endl;
		player.endPhase();
		return;
	}

	if (!askYesNoQuestion("Do you want to buy cards?", 'y', 'n')) {
		player.endPhase();
		return;
	}

	unordered_set<GameCard*> cardsToBeBought;

	int cardPosition = 0;
	bool done = false;
	while (cardsToBeBought.size() < cardsAvailable->size() && player.getEnergyCubes() > 0 && (cardPosition = askChoiceQuestion("Enter the position of the card that you want to buy: (0)to deal new cards (-1) to buy cards", -1, cardsAvailable->size() - 1)) != -1) {
		if (cardPosition != 0 && !cardsToBeBought.emplace(cardsAvailable->at(cardPosition - 1)).second) {
			cout << "This card is already in your basket" << endl;
		}
		else if (cardPosition == 0 && player.getEnergyCubes() >= 2) {
			this->dealNewCardsToBuy(player, cardsAvailable, deckOfCards);
		}
	}

	cout << "Content of your basket" << endl;

	for (auto iter : cardsToBeBought) {
		cout << *iter << endl;
	}

	for (auto card : cardsToBeBought) {
		auto cardToRemove = std::find(cardsAvailable->begin(), cardsAvailable->end(), card);
		if (cardToRemove != cardsAvailable->end()) {
			cardsAvailable->erase(cardToRemove);
		}
	}

	if (cardsToBeBought.size() > 0) {
		player.buyCards(cardsToBeBought);
	}

	for (auto card : cardsToBeBought) {
		deckOfCards->push(card);
	}
	deckOfCards->shuffle();
	cardsToBeBought.clear();
}

void InteractiveBuyingCardsStrategy::dealNewCardsToBuy(Player &player, vector<GameCard*> *cardsAvailable, Deck<GameCard*>* deckOfCards) {
	do {
		player.removeEnergyCubes(2);
		cout << "Player has " << player.getEnergyCubes() << " Energy Cubes" << endl;
		cardsAvailable->clear();
		for(int i = 0; i < 3; i++)
			cardsAvailable->push_back(*deckOfCards->deal());
		cout << "--Cards Available to buy--" << endl;

		for (auto iter : *cardsAvailable) {
			cout << *iter << endl;
		}
	} while (askYesNoQuestion("Do you want to deal new cards? (This will cost two energy cubes)", 'y', 'n') && player.getEnergyCubes() > 1);
}
