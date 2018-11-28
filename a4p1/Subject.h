#ifndef SUBJECT_H
#define SUBJECT_H
#include <list>
#include "Observer.h"

using namespace std;

class Subject {
public:
	Subject();
	virtual void attach(Observer* obs);
	virtual void detach(Observer* obs);
	virtual void notify();
	~Subject();
private:
	list<Observer*> *observers;
};
#endif
