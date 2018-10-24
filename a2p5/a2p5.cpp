#include "DiscardCard.h"
#include "KeepCard.h"
#include "Player.h"
#include <unordered_set>
#include <iostream>

using namespace std;

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

int main()
{
	MonsterCard *kong = new MonsterCard("Kong", "Funny");
	Player player(kong, 30, "Bronx", PlayerStateMachine::PlayerState::Buying);
	vector<GameCard> cardsAvailable;
	cardsAvailable.push_back(DiscardCard("Card 1", "Description", 1));
	cardsAvailable.push_back(KeepCard("Card 2", "Description", 2));
	cardsAvailable.push_back(DiscardCard("Card 3", "Description", 3));
	cout << "Here are the cards that are available to be bought:" << endl;
	printVector<GameCard>(cardsAvailable);
	char choice = -1;
	while (choice != 'y' && choice != 'N') {
		cout << "Do you want to buy any of the cards?(y)es or (N)o:";
		cin >> choice;
	}

	unordered_set<GameCard*> cardsToBeBought;
	cout << "Enter the position of the card that you want to buy: (-1)to buy the cards" << endl;
	int cardPosition = 0;
	cin >> cardPosition;
	while (cardsToBeBought.size() < cardsAvailable.size() && cardPosition != -1) {
		if ((cardPosition < 0 && cardPosition != -1) || cardPosition > cardsAvailable.size()) {
			cout << "Only position between 1 and " << cardsAvailable.size() << " are accepted" << endl;
		}
		else if (!cardsToBeBought.emplace(&cardsAvailable.at(cardPosition - 1)).second) {
			cout << "This card is already in your basket" << endl;
		}
		cin >> cardPosition;
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