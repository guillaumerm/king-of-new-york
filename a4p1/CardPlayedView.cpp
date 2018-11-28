#include "CardPlayedView.h"

void CardPlayedView::update(std::string name, std::string description, int cost) {
	this->cardsPlayed.emplace(name, description);
}

void CardPlayedView::show() {
	std::cout << " ----- Cards Played This Turn ----- " << std::endl;
	for (auto playedCard : this->cardsPlayed) {
		std::cout << "Name: " << playedCard.first << " Description: " << playedCard.second << std::endl;
	}
	std::cout << " ----- Cards Played This Turn ----- " << std::endl;
}

void CardPlayedView::clear() {
	this->cardsPlayed.clear();
}
