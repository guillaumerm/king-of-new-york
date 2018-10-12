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
	const int NUM_JINX = 12;
	const int NUM_WEB = 12;
	const int NUM_CARAPACE = 11;
	const int NUM_SOUVENIR = 11;
}

template <class T> void printDeck(Deck<T>* deck) {
	cout << "Deck (" << endl;
	for (int i = 0; i < deck->size(); i++) {
		cout << **(*deck)[i] << endl;
	}
	cout << ")" << endl;
}

template <class T> void printArray(T* array, int size) {
	cout << "Array [" << endl;
	for (int i = 0; i < size; i++) {
		cout << array[i] << endl;
	}
	cout << "]" << endl;
}

Token* initTokens(int numWeb, int numJinx, int numCara, int numSouv) {
	Token* tokens = new Token[46];
	for (int i = 0; i < numWeb + numJinx + numCara + numSouv; i++) {
		if (i < numWeb) {
			tokens[i] = Token("Web", "Web Token", Token::Type::Web);
		}
		else if (i < numWeb + numJinx) {
			tokens[i] = Token("Jinx", "Jinx Token", Token::Type::Jinx);
		}
		else if (i < numWeb + numJinx + numCara) {
			tokens[i] = Token("Carapace", "Carapace Token", Token::Type::Carapace);
		}
		else {
			tokens[i] = Token("Souvenir", "Souvenir Token", Token::Type::Souvenir);
		}
	}

	return tokens;
}

Deck<GameCard*>* initDeck() {
	Deck<GameCard*>* deckOfCards = new Deck<GameCard*>(64);

	deckOfCards->push(new GoalCard("Superstar", "Take this card when you roll at least 3 stars, and gain 1 Victory Point, +1 Victory Point per additional Stars you rolled. While you have this card, you gain 1 Victory Point for each star you roll"));
	deckOfCards->push(new GoalCard("Statue of Liberty", "Take this card when you roll at least 3 skulls. +3 Victory Points you take this card. -3 Victory Points you lose this card."));
	
	for (int i = 0; i < 31; i++) {
		deckOfCards->push(new DiscardCard("DiscardCard " + to_string(i+1), "DiscardCard", i+1));
	}

	for (int i = 32; i < 63; i++) {
		deckOfCards->push(new KeepCard("KeepCard " + to_string(i + 1 - 32), "KeepCard", (i-32)+1));
	}

	
	return deckOfCards;
}

inline MonsterCard* initMonsterCards() {
	MonsterCard* monsterCards = new MonsterCard[6];
	monsterCards[0] = MonsterCard("Sherif", "A TRex sherif");
	monsterCards[1] = MonsterCard("Kong", "A futuristic looking Ape");
	monsterCards[2] = MonsterCard("Captain Fish", "Captain of the \"fishes\"");
	monsterCards[3] = MonsterCard("Drakonis", "A laser-beam weilding dragon");
	monsterCards[4] = MonsterCard("Rob", "A funny looking robot");
	monsterCards[5] = MonsterCard("Mantis", "A chainsaw weilding giant prey mantis");
	return monsterCards;
}



int main() {
	Token* tokens = initTokens(GameCoponentDriver::NUM_WEB, GameCoponentDriver::NUM_JINX, GameCoponentDriver::NUM_CARAPACE, GameCoponentDriver::NUM_SOUVENIR);
	printArray<Token>(tokens, 46);
	MonsterCard* monsterCards = initMonsterCards();
	printArray<MonsterCard>(monsterCards, 6);

	Deck<GameCard*>* deckOfCards = initDeck();

	cout << "Deck Before Suffle" << endl;
	printDeck<GameCard*>(deckOfCards);
	deckOfCards->shuffle();
	cout << "Deck After Suffle" << endl;
	printDeck<GameCard*>(deckOfCards);
	delete[] tokens;
	tokens = NULL;
	delete deckOfCards;
	deckOfCards = NULL;
	delete[] monsterCards;
	monsterCards = NULL;
	system("pause");
	return 0;
}