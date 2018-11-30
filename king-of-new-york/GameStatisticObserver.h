#ifndef GAME_STATISTIC_OBSERVER_H
#define GAME_STATISTIC_OBSERVER_H
#include <string>
/**
 * @brief An interface that is used to declare the behavior that GameStatisticObserver will require to be able to observe GameStatisticSubject.
 */
class GameStatisticObserver {
public:
	/**
	 * Method used by GameStatisticSubject to notify the view that a change as occured.
	 * @param playerName name of the subject
	 * @param location current location of the subject
	 * @param victoryPoints current number of victory points being held by the player
	 * @param healPoints current number of heal points that a player has
	 * @param energyCubes current number of energy cubes held by the player
	 */
	virtual void update(std::string playerName, std::string location, int victoryPoints, int healPoints, int energyCubes) = 0;
};
#endif
