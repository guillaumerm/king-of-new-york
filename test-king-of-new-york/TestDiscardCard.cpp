#include "pch.h"
#include "DiscardCard.h"
#include "DiscardCard.cpp"

TEST(DiscardCard, TestClassInit) {
	string name = "DiscardCard Name";
	string description = "DiscardCard Description";
	int cost = 2;

	DiscardCard dc1(name, description, cost);
	EXPECT_EQ(dc1.getName(), name);
	EXPECT_EQ(dc1.getDescription(), description);
	EXPECT_EQ(dc1.getCost(), cost);
	EXPECT_EQ(dc1.getLinkedBorough(), " ");

	string linkedBorough = NULL;

	DiscardCard dc2(name, description, cost, linkedBorough);
	EXPECT_EQ(dc2.getName(), name);
	EXPECT_EQ(dc2.getDescription(), description);
	EXPECT_EQ(dc2.getCost(), cost);
	EXPECT_EQ(dc2.getLinkedBorough(), linkedBorough);
}

TEST(DiscardCard, getLinkedBorough) {
	string name = "DiscardCard Name";
	string description = "DiscardCard Description";
	int cost = 2;
	string linkedBorough = NULL;

	DiscardCard dc(name, description, cost, linkedBorough);

	EXPECT_EQ(dc.getLinkedBorough(), linkedBorough);
}