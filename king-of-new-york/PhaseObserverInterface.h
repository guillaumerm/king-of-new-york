#ifndef PHASE_OBSERVER_INTERFACE_H
#define PHASE_OBSERVER_INTERFACE_H
#include <iostream>
 
/**
 * @brief An interface that regroup console output functions used by concrete PhaseObserverInterface
 */
class PhaseObserverInterface {
public:
	/**
	 * Display the current information about the current phase that the Player is playing.
	 */
	virtual void show() = 0;
};
#endif
