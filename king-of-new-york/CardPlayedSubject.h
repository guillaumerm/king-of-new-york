#ifndef CARD_PLAYED_SUBJECT_H
#define CARD_PLAYED_SUBJECT_H
#include <string>
#include <list>
#include "CardPlayedObserver.h"

class CardPlayedSubject {
public:
	CardPlayedSubject();
	virtual void notify(std::string name, std::string description, int cost);
	void attach(CardPlayedObserver *ob);
	void detach(CardPlayedObserver *ob);
	~CardPlayedSubject();
private:
	std::list<CardPlayedObserver*> *observers;
};
#endif
