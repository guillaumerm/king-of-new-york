#include "DeckCard-impl.cpp"
#include "GameCard.h"
#include "DiscardCard.h"
#include "KeepCard.h"
#include "GoalCard.h"
#include "MonsterCard.h"
#include "EnergyCube.h"
#include "Token.h"
#include <new>

namespace GameCoponentDriver {
	const int NUM_JINX = 13;
	const int NUM_WEB = 13;
	const int NUM_CARAPACE = 12;
	const int NUM_SOUVENIR = 12;
}

template <class T> void printDeck(Deck<T>* deck) {
	cout << "Deck Before Suffle" << endl;
	cout << "Deck (" << endl;
	for (int i = 0; i < deck->size(); i++) {
		cout << *(*deck)[i] << endl;
	}
	cout << ")" << endl;
}

template <class T> void printArray(T** array, int size) {
	cout << "Array [" << endl;
	for (int i = 0; i < size; i++) {
		cout << *(array+1) << endl;
	}
	cout << "]" << endl;
}

Token** initTokens(int numWeb, int numJinx, int numCara, int numSouv) {
	Token* tokens[46];

	for (int i = 0; i < numWeb; i++) {
		tokens[i] = new Token("Web", "Web Token", Token::Type::Web);
	}

	for (int i = 0; i < numJinx; i++) {
		tokens[i] = new Token("Jinx", "Jinx Token", Token::Type::Jinx);
	}

	for (int i = 0; i < numCara; i++) {
		tokens[i] = new Token("Carapace", "Carapace Token", Token::Type::Carapace);
	}

	for (int i = 0; i < numSouv; i++) {
		tokens[i] = new Token("Souvenir", "Souvenir Token", Token::Type::Souvenir);
	}

	return tokens;
}

Deck<GameCard>* initDeck() {
	return NULL;
}



int main() {
	Token** tokens = initTokens(GameCoponentDriver::NUM_WEB, GameCoponentDriver::NUM_JINX, GameCoponentDriver::NUM_CARAPACE, GameCoponentDriver::NUM_SOUVENIR);
	//printArray<Token>(tokens, GameCoponentDriver::NUM_WEB+GameCoponentDriver::NUM_JINX+GameCoponentDriver::NUM_CARAPACE+GameCoponentDriver::NUM_SOUVENIR);

	GameCard* cards[10];

	for (int i = 0; i < 10; i++) {
		cards[i] = new DiscardCard("Test " + to_string(i), "Test", i);
		cout << *cards[i] << endl;
	}

	Deck<GameCard>* deckOfCards = new Deck<GameCard>(cards, 10);

	printDeck<GameCard>(deckOfCards);
	deckOfCards->shuffle();
	printDeck<GameCard>(deckOfCards);
	system("pause");
	return 0;
}