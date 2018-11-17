#ifndef PHASE_SUBJECT_H
#define PHASE_SUBJECT_H
#include <list>
#include "PhaseObserver.h"

using namespace std;

class PhaseSubject {
public:
	PhaseSubject();
	virtual void attach(PhaseObserver* obs);
	virtual void detach(PhaseObserver* obs);
	virtual void notify();
	~PhaseSubject();
private:
	list<PhaseObserver*> *observers;
};
#endif
