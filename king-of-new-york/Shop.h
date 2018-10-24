#pragma once
#include "GameCard.h"
#include <array>

class Shop {
public:
	static int DEFAULT_NUM_CARDS;
	static Shop *getInstance();
	array<GameCard *, 3> getAvailableCards();
	void setAvailableCardAt(GameCard *card, int index);
private:
	Shop();
	array<GameCard *, 3> availableCards;
	static Shop *instance;
};