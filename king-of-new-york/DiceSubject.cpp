#include "DiceSubject.h"

void DiceSubject::attach(DiceObserver * obs) {
	this->observers->push_back(obs);
}

void  DiceSubject::detach(DiceObserver * obs) {
	this->observers->remove(obs);
}

void  DiceSubject::notify() {
	for (auto o : *this->observers) {
		o->update();
	}
}

DiceSubject::DiceSubject() {
	this->observers = new list<DiceObserver*>();
}

DiceSubject::~DiceSubject() {
	delete this->observers;
}