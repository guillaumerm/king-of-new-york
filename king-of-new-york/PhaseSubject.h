#ifndef PHASE_SUBJECT_H
#define PHASE_SUBJECT_H
#include <list>
#include "PhaseObserver.h"

using namespace std;

/**
 * @brief An interface that regroup behavior of a PhaseSubject, that is a subject that is being observed by a PhaseObserver.
 */
class PhaseSubject {
public:
	/**
	 * Parameterless construct. Return an instance of the class.
	 */
	PhaseSubject();

	/**
	 * Register a PhaseObserver to get notified when the PhaseSubject is subject of a state change.
	 */
	virtual void attach(PhaseObserver* obs);

	/**
	 * Unregister a previously registered PhaseObserver. That is the observer will not be notify from this point forward.
	 */
	virtual void detach(PhaseObserver* obs);

	/**
	 * Notifies the PhaseObservers that the PhaseSubject state as changed.
	 */
	virtual void notify();

	/** 
	 * Deconstructor
	 */
	~PhaseSubject();
private:
	list<PhaseObserver*> *observers; /** < List of registered PhaseObservers*/
};
#endif
