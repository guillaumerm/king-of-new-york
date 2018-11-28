#ifndef GAME_STATISTIC_OBSERVER_H
#define GAME_STATISTIC_OBSERVER_H
#include <string>
/**
 * @brief An interface that is used to declare the behavior that GameStatisticObserver will require to be able to observe GameStatisticSubject.
 */
class GameStatisticObserver {
public:
	/**
	 * Signal the GameStatisticObserver that the registered GameStatisticSubject had its state changed.
	 * @param playerName name of the subject
	 * @param location current location of the subject
	 * @param victoryPoints current number of victory points being held by the player
	 */
	virtual void update(std::string playerName, std::string location, int victoryPoints) = 0;
};
#endif
