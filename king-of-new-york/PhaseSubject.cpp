#include "PhaseSubject.h"

void PhaseSubject::attach(PhaseObserver * obs) {
	this->observers->push_back(obs);
}

void  PhaseSubject::detach(PhaseObserver * obs) {
	this->observers->remove(obs);
}

void  PhaseSubject::notify() {
	for (auto o : *this->observers) {
		o->update();
	}
}

PhaseSubject::PhaseSubject() {
	this->observers = new list<PhaseObserver*>();
}

PhaseSubject::~PhaseSubject() {
	delete this->observers;
}
