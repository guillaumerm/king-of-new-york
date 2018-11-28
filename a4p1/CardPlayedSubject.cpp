#include "CardPlayedSubject.h"

CardPlayedSubject::CardPlayedSubject() {
	this->observers = new std::list<CardPlayedObserver*>();
}

void CardPlayedSubject::notify(std::string name, std::string description, int cost) {
	for (auto observer : *this->observers) {
		observer->update(name, description, cost);
	}
}

void CardPlayedSubject::attach(CardPlayedObserver * ob) {
	this->observers->push_back(ob);
}

void CardPlayedSubject::detach(CardPlayedObserver * ob) {
	this->observers->remove(ob);
}

CardPlayedSubject::~CardPlayedSubject() {
	delete this->observers;
	this->observers = NULL;
}
