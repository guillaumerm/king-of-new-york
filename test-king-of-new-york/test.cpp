#include "pch.h"
#include "Card.h"
#include "Card.cpp"
#include "MonsterCard.h"
#include "MonsterCard.cpp"

TEST(MonsterCard, Constructor) {
	string emptyName = "";
	string emptyDescription = "";

	MonsterCard mc1;
	EXPECT_EQ(mc1.getName(), emptyName);
	EXPECT_EQ(mc1.getDescription(), emptyDescription);

	string name = "Name";
	string description = "Description";

	MonsterCard mc2(name, description);
	EXPECT_EQ(mc2.getName(), name);
	EXPECT_EQ(mc2.getDescription(), description);

	int lifePoints = 10;
	int victoryPoints = 0;

	MonsterCard mc3(name, description, lifePoints, victoryPoints);
	EXPECT_EQ(mc3.getName(), name);
	EXPECT_EQ(mc3.getDescription(), description);
	EXPECT_EQ(mc3.getLifePoint(), lifePoints);
	EXPECT_EQ(mc3.getVictoryPoint(), victoryPoints);
}

TEST(MonsterCard, addLifePoints) {
	string name = "Name";
	string description = "Description";
	int victoryPoints = 5;
	int lifePoints = 10;
	int lifePointsRemoved = 3;

	MonsterCard mc(name, description, lifePoints, victoryPoints);
	mc.removeLifePoints(3);
	EXPECT_EQ((lifePoints - lifePointsRemoved), mc.getLifePoint());
}