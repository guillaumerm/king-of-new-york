#ifndef DICE_VIEW_H
#define DICE_VIEW_H
#include "Player.h"
#include "DiceObserver.h"
#include "DiceObserverInterface.h"

/**
 * @brief A view which is used to keep track the description of each dice roll.
 */
class DiceView : public DiceObserver, DiceObserverInterface {
public:
	/**
	 * Method used by DiceSubject to notify the view that a change as occured.
	 */
	void update();

	/**
	 * Method used to display the last dice roll of the current playing player.
	 */
	void show();

	/**
	 * Sets the current dice rolling facility of the current player that is the concrete DiceSubject
	 */
	void setCurrentFacility(DiceRollingFacility * rollFacility);
private:
	DiceRollingFacility* currentRollFacil; /** < Pointer to the concrete DiceSubject */
};
#endif