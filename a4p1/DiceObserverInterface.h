#ifndef DICE_OBSERVER_INTERFACE_H
#define DICE_OBSERVER_INTERFACE_H
#include <iostream>

/**
 * @brief An interface that regroup console output functions used by concrete DiceObserverInterface
 */
class DiceObserverInterface {
public:
	/**
	 * Display the current information about the current dice roll.
	 */
	virtual void show() = 0;
};
#endif