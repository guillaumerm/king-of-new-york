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
		cards[i] = new DiscardCard("Test", "Test", i);
	}
	Deck<GameCard>* deckOfCards = new Deck<GameCard>(cards, 10);
	return 0;
}