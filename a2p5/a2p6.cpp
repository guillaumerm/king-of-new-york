#include "DiscardCard.h"
#include "KeepCard.h"
#include "Player.h"
#include <unordered_set>
#include <iostream>

using namespace std;

static vector <GameCard>cardsAvailable;

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

void executeBuyCardsPhase(Player &player) {
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

void dealNewCardsToBuy(Player &player) {
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

int main()
{
	MonsterCard *kong = new MonsterCard("Kong", "Funny");
	Player player(kong, 10, "Bronx", PlayerStateMachine::PlayerState::Buying);

	cardsAvailable.push_back(DiscardCard("Card 1", "Description", 1));
	cardsAvailable.push_back(KeepCard("Card 2", "Description", 2));
	cardsAvailable.push_back(DiscardCard("Card 3", "Description", 3));
	cout << "Here are the cards that are available to be bought:" << endl;
	printVector<GameCard>(cardsAvailable);

	// ask if the player wants to buy cards buying cards
	bool answer = askYesNoQuestion("Do you want to buy any of the cards?", 'y', 'n');

	// redealing cards
	if (player.getEnergyCubes() > 1 && !answer && askYesNoQuestion("Do you want to deal new cards? (This will cost two energy cubes)", 'y', 'n')) {
		dealNewCardsToBuy(player);
		answer = askYesNoQuestion("Do you want to buy any of the cards?", 'y', 'n');
	}

	if (answer) {
		//buying new cards
		executeBuyCardsPhase(player);
	}


	return 0;
}