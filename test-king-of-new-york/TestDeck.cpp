#include "pch.h"
#include "Deck.h"
#include "Deck.cpp"

TEST(Deck, TestClassInit) {
	Deck<int> deck(0);
	EXPECT_TRUE(deck.isEmpty());
}

TEST(Deck, push) {
	Deck<int> deck(10);
	int pushedValue = 10;
	deck.push(pushedValue);
	EXPECT_EQ(*deck[0], pushedValue);
}

TEST(Deck, pushFullDeck) {
	Deck<int> deck(2);
	deck.push(1);
	deck.push(1);
	EXPECT_THROW(deck.push(1), exception);
}

TEST(Deck, dealEmptyDeck) {
	Deck<int> deck(0);
	EXPECT_THROW(deck.deal(), out_of_range);
}

TEST(Deck, isEmpty) {
	Deck<int> deck(1);
	EXPECT_TRUE(deck.isEmpty());
	deck.push(1);
	EXPECT_FALSE(deck.isEmpty());
}

TEST(Deck, size) {
	Deck<int> deck(1);
	EXPECT_EQ(deck.size(), 0);
	deck.push(1);
	EXPECT_EQ(deck.size(), 1);
}

TEST(Deck, shuffle) {
	Deck<int> deck(10);
	for (int i = 0; i < 10; i++) {
		deck.push(i);
	}
	deck.shuffle();
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 8; j++) {
			EXPECT_NE(deck[i], deck[j]);
		}
	}
}

