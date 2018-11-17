#include "InteractiveBuyingCardsStrategy.h"

void InteractiveBuyingCardsStrategy::execute(Player & player, vector<GameCard*> cardsAvailable, Deck<GameCard*> *deckOfCards) {
	cout << "--Cards Available to buy--" << endl;
	
	for (auto iter : cardsAvailable) {
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

	int cardPosition = -1;
	bool done = false;
	while (cardsToBeBought.size() < cardsAvailable.size() && player.getEnergyCubes() > 0 && cardPosition != -1) {
		cardPosition = askChoiceQuestion("Enter the position of the card that you want to buy: (0)to deal new cards (-1) to buy cards", -1, cardsAvailable.size() - 1);
		if (cardPosition != 0 && !cardsToBeBought.emplace(cardsAvailable.at(cardPosition - 1)).second) {
			cout << "This card is already in your basket" << endl;
		}
		else if (cardPosition == 0 && player.getEnergyCubes() >= 2) {
			//dealNewCardsToBuy(player, cardsAvailable);
		}
	}

	cout << "Content of your basket" << endl;

	for (auto iter : cardsToBeBought) {
		cout << *iter << endl;
	}

	if (cardsToBeBought.size() > 0) {
		player.buyCards(cardsToBeBought);
	}

	player.endPhase();
}
