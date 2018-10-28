#include "Shop.h"

int Shop::DEFAULT_NUM_CARDS = 3;

Shop::Shop() {}

Shop *Shop::getInstance() {
	if (!Shop::instance)
		Shop::instance = new Shop();
	return Shop::instance;
}

array<GameCard *, 3> Shop::getAvailableCards() {
	return this->availableCards;
}

void Shop::setAvailableCardAt(GameCard *card, int index) {
	this->availableCards[index] = card;
}