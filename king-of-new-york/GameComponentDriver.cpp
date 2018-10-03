#include "DeckCard-impl.cpp"
#include "GameCard.h"
#include "DiscardCard.h"
#include "KeepCard.h"
#include "GoalCard.h"
#include "MonsterCard.h"
#include <new>

int main() {
	DiscardCard* card = new DiscardCard("Test", "Test", 0);
	GameCard* cards[10];
	for (int i = 0; i < 10; i++) {
		cards[i] = new DiscardCard("Test " + to_string(i), "Test", i);
		cout << *cards[i] << endl;
	}

	Deck<GameCard>* deckOfCards = new Deck<GameCard>(cards, 10);
	cout << "Deck Before Suffle" << endl;
	cout << "Deck (" << endl;
	for (int i = 0; i < deckOfCards->size(); i++) {
		cout << *deckOfCards->get(i) << endl;
	}
	cout << ")" << endl;
	deckOfCards->shuffle();
	cout << "Deck After Suffle" << endl;
	cout << "Deck (" << endl;
	for (int i = 0; i < deckOfCards->size(); i++) {
		cout << *deckOfCards->get(i) << endl;
	}
	cout << ")" << endl;
	system("pause");
	return 0;
}