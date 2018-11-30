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
	Deck<GameCard*>* deckOfCards = new Deck<GameCard*>(27);

	//deckOfCards->push(new GoalCard("Superstar", "Take this card when you roll at least 3 stars, and gain 1 Victory Point, +1 Victory Point per additional Stars you rolled. While you have this card, you gain 1 Victory Point for each star you roll"));
	//deckOfCards->push(new GoalCard("Statue of Liberty", "Take this card when you roll at least 3 skulls. +3 Victory Points you take this card. -3 Victory Points you lose this card."));
	GameCard* card;

	for (int i = 0; i < 3; i++) {
		card = new AddToRollKeepCard("Towering Titan", "Add 2 ATTACK to your result", 10, Die::Face::A, 2);
		card->attach(observer);
		deckOfCards->push(card);
	}

	for (int i = 0; i < 3; i++) {
		card = new AddToRollKeepCard("Tiny Titan Turrent", "Add 1 ATTACK to your result", 5, Die::Face::A, 1);
		card->attach(observer);
		deckOfCards->push(card);
	}

	for (int i = 0; i < 3; i++) {
		card = new AddToRollKeepCard("Clever Name", "Add 2 HEAL to your result", 10, Die::Face::H, 1);
		card->attach(observer);
		deckOfCards->push(card);
	}
	
	for (int i = 0; i < 3; i++) {
		card = new AddToRollKeepCard("Chances of Rain EnergyCubes", "Add 1 ENERGY_CUBE to your result", 10, Die::Face::E, 1);
		card->attach(observer);
		deckOfCards->push(card);
	}

	for (int i = 0; i < 3; i++) {
		card = new AddToRollKeepCard("Clumsy Behemoth", "Add 1 OUCH to your result", 1, Die::Face::O, 1);
		card->attach(observer);
		deckOfCards->push(card);
	}

	for (int i = 0; i < 3; i++) {
		card = new GainPointsDiscardCard("Brooklyn Bridge", "Buy this card for 1 ENERGY_POINT less if you are in BROOKLYN. \n+4 VICTORY_POINT", 6, "Brooklyn", 0, 4, 0);
		card->attach(observer);
		deckOfCards->push(card);
	}

	for (int i = 0; i < 3; i++) {
		card = new GainPointsDiscardCard("Yankee Stadium", "Buy this card for 1 ENERGY less if you are in the BRONX.\n+5 VICTORY_POINT and heal 5 damage.", 9, "Bronx", 0, 5, 5);
		card->attach(observer);
		deckOfCards->push(card);
	}
	card = new GainPointsDiscardCard("North Central Park", "Buy this card for 1 ENERGY less if you are in the UPPER_MANHATTEN.\n+5 VICTORY_POINT and heal 5 damage.", 5, "Upper Manhatten", 0, 5, 5);
	card->attach(observer);
	deckOfCards->push(card);

	card = new GainPointsDiscardCard("South Central Park", "Buy this card for 1 ENERGY less if you are in the LOWER_MANHATTEN.\n+5 VICTORY_POINT and heal 5 damage.", 5, "Lower Manhatten", 0, 5, 5);
	card->attach(observer);
	deckOfCards->push(card);

	for (int i = 0; i < 3; i++) {
		card = new GainPointsDiscardCard("The Unisphere", "Buy this card for 1 ENERGY_POINT less if you are in QUEENS.\n+4 VICTORY_POINT.", 5, "Queens", 0, 4, 0);
		card->attach(observer);
		deckOfCards->push(card);
	}

	deckOfCards->shuffle();

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