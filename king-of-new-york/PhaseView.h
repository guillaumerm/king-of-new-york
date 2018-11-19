#ifndef PHASE_VIEW_H
#define PHASE_VIEW_H
#include "Player.h"
#include "PhaseObserver.h"
#include "PhaseObserverInterface.h"

/**
 * @brief A view which is used to keep track the description of each phases.
 */
class PhaseView : public PhaseObserver, PhaseObserverInterface {
public:
	/**
	 * Method used by PhaseSubject to notify the view that a change as occured.
	 */
	void update();

	/**
	 * Method used to display the last phase of the current playing player.
	 */
	void show();

	/**
	 * Sets the current playing player that is the concrete PhaseSubject
	 */
	void setCurrentPlayer(Player *player);
private:
	Player* currentPlayer; /** < Pointer to the concrete PhaseSubject */
};
#endif