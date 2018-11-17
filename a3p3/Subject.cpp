#include "Subject.h"

void Subject::attach(Observer * obs) {
	this->observers->push_back(obs);
}

void Subject::detach(Observer * obs) {
	this->observers->remove(obs);
}

void Subject::notify() {
	for (auto o : *this->observers) {
		o->update();
	}
}

Subject::Subject() {
	this->observers = new list<Observer*>();
}

Subject::~Subject() {
	delete this->observers;
}
