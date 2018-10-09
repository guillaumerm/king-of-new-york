#include "pch.h"
#include "Player.h"
#include "Player.cpp"


TEST(Player, TestClassInit) {
	MonsterCard monsterCard("Player Monster Card", "Player Monster Card");
	Player player(&monsterCard, 30);
	EXPECT_NO_THROW();
}