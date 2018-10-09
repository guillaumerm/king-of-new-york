#include "pch.h"
#include "Card.h"
#include "GameCard.h"
#include "GameCard.cpp"
#include "KeepCard.h"
#include "KeepCard.cpp"

TEST(KeepCard, TestClassInit) {
	KeepCard kc;
	EXPECT_EQ(kc.getName(), "");
	EXPECT_EQ(kc.getDescription(), "");
	EXPECT_EQ(kc.getCost(), 0);
	EXPECT_EQ(kc.isFacingUp(), true);
	
	string name = "KeepCard";
	string description = "KeepCard";
	int cost = 10;
	bool facingUp = true;

	KeepCard kc1(name, description, cost, facingUp);
	EXPECT_EQ(kc1.getName(), name);
	EXPECT_EQ(kc1.getDescription(), description);
	EXPECT_EQ(kc1.getCost(), cost);
	EXPECT_TRUE(kc1.isFacingUp());
}

TEST(KeepCard, isFacingUp) {
	string name = "KeepCard";
	string description = "KeepCard";
	int cost = 10;
	bool facingUp = false;

	KeepCard kc1(name, description, cost, facingUp);
	EXPECT_FALSE(kc1.isFacingUp());
}
