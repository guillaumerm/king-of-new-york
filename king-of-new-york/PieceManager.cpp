#include "PieceManager.h"

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

Deck<GameCard*>* initDeck(CardPlayedObserver *observer) {
	Deck<GameCard*>* deckOfCards = new Deck<GameCard*>(20);

	//deckOfCards->push(new GoalCard("Superstar", "Take this card when you roll at least 3 stars, and gain 1 Victory Point, +1 Victory Point per additional Stars you rolled. While you have this card, you gain 1 Victory Point for each star you roll"));
	//deckOfCards->push(new GoalCard("Statue of Liberty", "Take this card when you roll at least 3 skulls. +3 Victory Points you take this card. -3 Victory Points you lose this card."));

	for (int i = 0; i < 3; i++) {
		deckOfCards->push(new AddToRollKeepCard(Die::Face::A, 1));
	}

	for (int i = 0; i < 3; i++) {
		deckOfCards->push(new AddToRollKeepCard(Die::Face::H, 1));
	}
	
	for (int i = 0; i < 3; i++) {
		deckOfCards->push(new AddToRollKeepCard(Die::Face::E, 1));
	}

	for (int i = 0; i < 3; i++) {
		deckOfCards->push(new AddToRollKeepCard(Die::Face::O, 1));
	}



	return deckOfCards;
}

MonsterCard* initMonsterCards() {
	MonsterCard* monsterCards = new MonsterCard[6];
	monsterCards[0] = MonsterCard("Sherif", "A TRex sherif");
	monsterCards[1] = MonsterCard("Kong", "A futuristic looking Ape");
	monsterCards[2] = MonsterCard("Captain Fish", "Captain of the \"fishes\"");
	monsterCards[3] = MonsterCard("Drakonis", "A laser-beam weilding dragon");
	monsterCards[4] = MonsterCard("Rob", "A funny looking robot");
	monsterCards[5] = MonsterCard("Mantis", "A chainsaw weilding giant prey mantis");
	return monsterCards;
}