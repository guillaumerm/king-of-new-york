#include "pch.h"
#include "Die.h"
#include "Die.cpp"

TEST(Die, TestClassInit) {

}

TEST(Die, roll) {
	Die::Face expectedRoll = (Die::Face)(rand() % 6 + 0);
	Die die;
	EXPECT_EQ(die.roll(), expectedRoll);
}

TEST(Die, getLastRoll) {
	Die die;
	Die::Face expectedRoll = die.roll();
	EXPECT_EQ(die.getLastRoll(), expectedRoll);
}