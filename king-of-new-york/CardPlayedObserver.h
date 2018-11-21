#ifndef CARD_PLAYED_OBSERVER_H
#define CARD_PLAYED_OBSERVER_H
#include <string>

class CardPlayedObserver {
public:
	virtual void update(std::string name, std::string description, int cost) = 0;
};
#endif
