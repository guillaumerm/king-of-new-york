#include "pch.h"
#include "DiceRoll.h"
#include "DiceRoll.cpp"

TEST(DiceRoll, TestClassIniti) {
	Die::Face roll[5] = { Die::Face::A };
	DiceRoll diceRoll(roll, 5);
	EXPECT_EQ(diceRoll.getNumberDice(), 5);
}

TEST(DiceRoll, getSumAttack) {
	Die::Face roll1[4] = { Die::Face::A, Die::Face::A, Die::Face::C, Die::Face::H };
	DiceRoll diceRoll1(roll1, 4);
	EXPECT_EQ(diceRoll1.getSumAttack(), 2);

	Die::Face roll2[4] = { Die::Face::H, Die::Face::O, Die::Face::C, Die::Face::H };
	DiceRoll diceRoll2(roll2, 4);
	EXPECT_EQ(diceRoll2.getSumAttack(), 0);
}

TEST(DiceRoll, getSumCelebrity) {
	Die::Face roll1[4] = { Die::Face::C, Die::Face::C, Die::Face::H, Die::Face::H };
	DiceRoll diceRoll1(roll1, 4);
	EXPECT_EQ(diceRoll1.getSumCelebrity(), 2);

	Die::Face roll2[4] = { Die::Face::H, Die::Face::O, Die::Face::O, Die::Face::H };
	DiceRoll diceRoll2(roll2, 4);
	EXPECT_EQ(diceRoll2.getSumCelebrity(), 0);
}

TEST(DiceRoll, getSumDesctruction) {
	Die::Face roll1[4] = { Die::Face::D, Die::Face::C, Die::Face::H, Die::Face::D };
	DiceRoll diceRoll1(roll1, 4);
	EXPECT_EQ(diceRoll1.getSumDesctruction(), 2);

	Die::Face roll2[4] = { Die::Face::H, Die::Face::O, Die::Face::O, Die::Face::H };
	DiceRoll diceRoll2(roll2, 4);
	EXPECT_EQ(diceRoll2.getSumDesctruction(), 0);
}

TEST(DiceRoll, getSumEnergy) {
	Die::Face roll1[4] = { Die::Face::D, Die::Face::E, Die::Face::E, Die::Face::D };
	DiceRoll diceRoll1(roll1, 4);
	EXPECT_EQ(diceRoll1.getSumEnergy(), 2);

	Die::Face roll2[4] = { Die::Face::H, Die::Face::O, Die::Face::O, Die::Face::H };
	DiceRoll diceRoll2(roll2, 4);
	EXPECT_EQ(diceRoll2.getSumEnergy(), 0);
}

TEST(DiceRoll, getSumHeal) {
	Die::Face roll1[4] = { Die::Face::D, Die::Face::H, Die::Face::E, Die::Face::H };
	DiceRoll diceRoll1(roll1, 4);
	EXPECT_EQ(diceRoll1.getSumHeal(), 2);

	Die::Face roll2[4] = { Die::Face::O, Die::Face::O, Die::Face::O, Die::Face::E };
	DiceRoll diceRoll2(roll2, 4);
	EXPECT_EQ(diceRoll2.getSumHeal(), 0);
}

TEST(DiceRoll, getSumOuch) {
	Die::Face roll1[4] = { Die::Face::D, Die::Face::H, Die::Face::O, Die::Face::O };
	DiceRoll diceRoll1(roll1, 4);
	EXPECT_EQ(diceRoll1.getSumOuch(), 2);

	Die::Face roll2[4] = { Die::Face::A, Die::Face::C, Die::Face::E, Die::Face::E };
	DiceRoll diceRoll2(roll2, 4);
	EXPECT_EQ(diceRoll2.getSumOuch(), 0);
}

TEST(DiceRoll, getFaceAt) {
	Die::Face roll1[4] = { Die::Face::D, Die::Face::H, Die::Face::O, Die::Face::O };
	DiceRoll diceRoll1(roll1, 4);
	for (int i = 0; i < 4; i++) {
		EXPECT_EQ(diceRoll1.getFaceAt(i), roll1[i]);
	}
}

TEST(DiceRoll, getFaceAtOverRange) {
	Die::Face roll1[4] = { Die::Face::D, Die::Face::H, Die::Face::O, Die::Face::O };
	DiceRoll diceRoll1(roll1, 4);
	EXPECT_THROW(diceRoll1.getFaceAt(5), out_of_range);
}

TEST(DiceRoll, getFaceAtBelowRange) {
	Die::Face roll1[4] = { Die::Face::D, Die::Face::H, Die::Face::O, Die::Face::O };
	DiceRoll diceRoll1(roll1, 4);
	EXPECT_THROW(diceRoll1.getFaceAt(-1), out_of_range);
}