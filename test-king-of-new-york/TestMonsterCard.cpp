#include "pch.h"
#include "Card.h"
#include "Card.cpp"
#include "MonsterCard.h"
#include "MonsterCard.cpp"

TEST(MonsterCard, TestClassInit) {
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
	int lifePoints = 7;
	int lifePointsAdded = 3;

	MonsterCard mc(name, description, lifePoints, victoryPoints);
	mc.addLifePoints(lifePointsAdded);
	EXPECT_EQ((lifePoints + lifePointsAdded), mc.getLifePoint());
}

TEST(MonsterCard, addLifePointsOverLimit) {
	string name = "Name";
	string description = "Description";
	int victoryPoints = 5;
	int lifePoints = 10;
	int lifePointsAdded = 3;

	MonsterCard mc(name, description, lifePoints, victoryPoints);
	mc.addLifePoints(lifePointsAdded);
	EXPECT_EQ(lifePoints, mc.getLifePoint());
}

TEST(MonsterCard, addVictoryPoints) {
	string name = "Name";
	string description = "Description";
	int victoryPoints = 5;
	int lifePoints = 7;
	int victoryPointsAdded = 3;

	MonsterCard mc(name, description, lifePoints, victoryPoints);
	mc.addVictoryPoints(victoryPointsAdded);
	EXPECT_EQ((victoryPoints + victoryPointsAdded), mc.getVictoryPoint());
}

TEST(MonsterCard, addVictoryPointsOverLimit) {
	string name = "Name";
	string description = "Description";
	int victoryPoints = 20;
	int lifePoints = 7;
	int victoryPointsAdded = 1;

	MonsterCard mc(name, description, lifePoints, victoryPoints);
	mc.addVictoryPoints(victoryPointsAdded);
	EXPECT_EQ(victoryPoints, mc.getVictoryPoint());
}

TEST(MonsterCard, removeLifePoints) {
	string name = "Name";
	string description = "Description";
	int victoryPoints = 20;
	int lifePoints = 10;
	int lifePointsRemoved = 3;

	MonsterCard mc(name, description, lifePoints, victoryPoints);
	mc.removeLifePoints(lifePointsRemoved);
	EXPECT_EQ((lifePoints-lifePointsRemoved), mc.getLifePoint());
}

TEST(MonsterCard, removeLifePointsBelowLimit) {
	string name = "Name";
	string description = "Description";
	int victoryPoints = 20;
	int lifePoints = 0;
	int lifePointsRemoved = 1;

	MonsterCard mc(name, description, lifePoints, victoryPoints);
	mc.removeLifePoints(lifePointsRemoved);
	EXPECT_EQ(lifePoints, mc.getLifePoint());
}

TEST(MonsterCard, removeVictoryPoints) {
	string name = "Name";
	string description = "Description";
	int victoryPoints = 20;
	int lifePoints = 0;
	int victoryPointsRemoved = 5;

	MonsterCard mc(name, description, lifePoints, victoryPoints);
	mc.removeVictoryPoints(victoryPointsRemoved);
	EXPECT_EQ((victoryPoints - victoryPointsRemoved), mc.getVictoryPoint());
}

TEST(MonsterCard, removeVictoryPointsBelowLimit) {
	string name = "Name";
	string description = "Description";
	int victoryPoints = 0;
	int lifePoints = 0;
	int victoryPointsRemoved = 1;

	MonsterCard mc(name, description, lifePoints, victoryPoints);
	mc.removeVictoryPoints(victoryPointsRemoved);
	EXPECT_EQ(victoryPoints, mc.getVictoryPoint());
}