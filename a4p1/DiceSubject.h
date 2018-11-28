#ifndef DICE_SUBJECT_H
#define DICE_SUBJECT_H
#include <list>
#include "DiceObserver.h"

using namespace std;

/**
 * @brief An interface that regroup behavior of a DiceSubject, that is a subject that is being observed by a DiceObserver.
 */
class DiceSubject {
public:
	/**
	 * Parameterless construct. Return an instance of the class.
	 */
	DiceSubject();

	/**
	 * Register a DiceObserver to get notified when the DiceSubject is subject of a state change.
	 */
	virtual void attach(DiceObserver* obs);

	/**
	 * Unregister a previously registered DiceObserver. That is the observer will not be notify from this point forward.
	 */
	virtual void detach(DiceObserver* obs);

	/**
	 * Notifies the DiceObservers that the DiceSubject state as changed.
	 */
	virtual void notify();

	/**
	 * Deconstructor
	 */
	~DiceSubject();
private:
	list<DiceObserver*> *observers; /** < List of registered PhaseObservers*/
};
#endif