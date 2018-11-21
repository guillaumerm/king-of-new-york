#ifndef CARD_PLAYED_VIEW_H
#define CARD_PLAYED_VIEW_H
#include <unordered_map>
#include <string>
#include <iostream>
#include "CardPlayedInterface.h"
#include "CardPlayedObserver.h"

class CardPlayedView: public CardPlayedInterface, public CardPlayedObserver {
public:
	void update(std::string name, std::string description, int cost);
	void show();
	void clear();
private:
	std::unordered_map<std::string, std::string> cardsPlayed;
};
#endif
