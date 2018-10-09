#include "pch.h"
#include "DiceRollingFacility.h"
#include "DiceRollingFacility.cpp"

TEST(DiceRollingFacility, TestClassInit) {
	EXPECT_NO_THROW(DiceRollingFacility drf);
}

TEST(DiceRollingFacility, getLastRollNoPreviousRoll) {
	DiceRollingFacility drf;
	EXPECT_TRUE(drf.getLastRoll() == nullptr);
}

TEST(DiceRollingFacility, rollZeroDice) {
	DiceRollingFacility drf;
	EXPECT_THROW(drf.roll(0), domain_error);
}

TEST(DiceRollingFacility, rollDice) {
	DiceRollingFacility drf;
	EXPECT_NO_THROW(drf.roll(6), domain_error);
}

TEST(DiceRollingFacility, getLastRoll) {
	DiceRollingFacility drf;
	const DiceRoll* diceRoll = drf.roll(6);
	EXPECT_EQ(drf.getLastRoll(), diceRoll);
}