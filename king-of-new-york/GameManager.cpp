#include "GameManager.h"
#include "Card.h"
#include "DiscardCard.h"
#include "KeepCard.h"

template <typename T> void printVector(vector<T> aVector) {
	typename vector<T>::iterator anIterator;
	for (anIterator = aVector.begin(); anIterator != aVector.end(); anIterator++) {
		cout << *anIterator << endl;
	}
}

template <typename T> void printSet(unordered_set<T*> aVector) {
	typename unordered_set<T*>::iterator anIterator;
	for (anIterator = aVector.begin(); anIterator != aVector.end(); anIterator++) {
		cout << **anIterator << endl;
	}
}

/**
 * Function used to aske a yes-no question.
 * @param question question being answered
 * @param positiveAnswer char representing a positive asnwer for the question
 * @param negativeAnswer char representing a negative answer for the question
 * @return true if answer with positiveAnswer, false if answered with a negativeAnswer
 */
bool askYesNoQuestion(string question, char positiveAnswer, char negativeAnswer) {
	char answer = -1;
	while (answer != positiveAnswer && answer != negativeAnswer) {
		cout << question << "(" << positiveAnswer << " or " << negativeAnswer << "):";
		cin >> answer;
	}
	return answer == positiveAnswer;
}

/**
 * Function used to asked a choice question.
 * @param question the question being asked
 * @param lowerChoice lower bound limit for choices

 */
int askChoiceQuestion(string question, int lowerChoice, int upperChoice) {
	int choice = -1;
	while (choice < lowerChoice || choice > upperChoice) {
		cout << question;
		cin >> choice;
	}
	return choice;
}

void executeStart() {

}

void executeStartupPhase() {

}

void executeBuyCardsPhase(Player &player, vector<GameCard> cardsAvailable) {
	unordered_set<GameCard*> cardsToBeBought;
	int cardPosition = -1;
	while (cardsToBeBought.size() < cardsAvailable.size() && cardPosition != 0) {
		cardPosition = askChoiceQuestion("Enter the position of the card that you want to buy: (0)to buy the cards", 0, cardsAvailable.size() - 1);
		if (cardPosition != 0 && !cardsToBeBought.emplace(&cardsAvailable.at(cardPosition - 1)).second) {
			cout << "This card is already in your basket" << endl;
		}
	}

	cout << "Content of your basket" << endl;
	printSet(cardsToBeBought);
	GameCard *cards = new GameCard[cardsToBeBought.size()];
	unordered_set<GameCard*>::iterator cardIter;
	int index = 0;
	for (cardIter = cardsToBeBought.begin(); cardIter != cardsToBeBought.end(); cardIter++) {
		cards[index++] = **cardIter;
	}
	player.buyCards(cards, cardsToBeBought.size());
}

void dealNewCardsToBuy(Player &player, vector<GameCard> cardsAvailable) {
	do {
		player.removeEnergyCubes(2);
		cout << "Player has " << player.getEnergyCubes() << " Energy Cubes" << endl;
		cardsAvailable.clear();
		cardsAvailable.push_back(DiscardCard("New Card 1", "Description", 1));
		cardsAvailable.push_back(KeepCard("New Card 2", "Description", 2));
		cardsAvailable.push_back(DiscardCard("New Card 3", "Description", 3));
		printVector<GameCard>(cardsAvailable);
	} while (askYesNoQuestion("Do you want to deal new cards? (This will cost two energy cubes)", 'y', 'n') && player.getEnergyCubes() > 1);
}


void executeRollDicePhase(Player &player, int numberOfDice) {
	bool *diceToKeep = new bool[numberOfDice];
	const DiceRoll *diceRoll = player.rollDice(numberOfDice);

	// While the player can roll/rerall continue this loop
	while (player.isRolling()) {
		cout << "You've rolled:" << *diceRoll << endl;

		// Asks if the player wants to reroll
		if (askYesNoQuestion("Do you want to reroll?", 'y', 'n')) {
			bool *diceToKeep = new bool[numberOfDice];

			// Dicide which dice to keep and which to roll.
			for (int i = 0; i < numberOfDice; i++) {
				diceToKeep[i] = askYesNoQuestion("Keep dice " + to_string(i + 1) + " which as symbol " + dieFaceToString(diceRoll->getFaceAt(i)), 'y', 'n');
			}

			diceRoll = player.rollDice(diceToKeep);
		}
		else {
			// End the rolling phase
			player.endPhase();
		}
	}
}


void executeResolveDicePhase(Player &player) {
	// Decide the order in which the dice will be played.
	unordered_set<Die::Face> order;
	while (order.size() < 6) {
		int choice = askChoiceQuestion("Enter the symbol of the dice you want to resolve [A(0), C(1), D(2), E(3), H(4), O(5)]:", 0, 5);

		if (!order.emplace((Die::Face)choice).second) {
			cerr << "You have already decided for this symbol." << endl;
		}
	}
	// Given the order obtain the count for each Die::Face from the last roll of the player
	unordered_map<Die::Face, int> resolveDecision = player.resolveDice(order);
	unordered_map<Die::Face, int>::iterator iter;

	cout << "The order you decided to resolve the dice is the following" << endl;

	for (iter = resolveDecision.begin(); iter != resolveDecision.end(); iter++) {
		cout << iter->first << " => " << iter->second << endl;
	}
}

void executeMovePhase(Player *player, GameMap *map) {
	vector<GameMapNode*> neighbours = map->getZoneByName(player->getCurrentZone())->getNeighbours();

	if (neighbours.size() == 0) {
		cout << "Since you are in Upper Manhatten you need to stay there." << endl;
		player->endPhase();
	}
	else if (neighbours.size() == 1) {
		cout << "Since you were in " << player->getCurrentZone() << " you were moved to " << neighbours.at(0)->getZoneName() << endl;
		player->move(map, neighbours.at(0)->getZoneName());
	}
	else {
		cout << "List of possible zones:" << endl;
		for (int i = 0; i < neighbours.size(); i++) {
			cout << (i + 1) << ")" << neighbours.at(i)->getZoneName() << endl;
		}
		int choice = askChoiceQuestion("Select which zone you want to move to? (0 to skip this phase)", 0, neighbours.size());
		if (choice != 0) {
			player->move(map, neighbours.at(choice - 1)->getZoneName());
		}
		else {
			player->endPhase();
		}
	}
}