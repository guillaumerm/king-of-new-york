#ifndef GAME_STATISTIC_SUBJECT_H
#define GAME_STATISTIC_SUBJECT_H
#include <list>
#include <string>
#include "GameStatisticObserver.h"

/**
 * @brief An interface that regroup behavior of a GameStatisticSubject, that is a subject that is being observed by a GameStatisticObserver.
 */
class GameStatisticSubject {
public:
	/**
	 * Parameterless construct. Return an instance of the class.
	 */
	GameStatisticSubject();

	/**
	 * Register a GameStatisticObserver to get notified when the GameStatisticSubject is subject of a state change.
	 */
	void attach(GameStatisticObserver *ob);

	/**
	 * Unregister a previously registered GameStatisticObserver. That is the observer will not be notify from this point forward.
	 */
	void detach(GameStatisticObserver *ob);

	/**
	 * Notifies the GameStatisticObservers that the GameStatisticSubject state as changed.
	 */
	void notify(std::string playerName, std::string location, int victoryPoint);

	/**
	 * Deconstructor
	 */
	~GameStatisticSubject();
private:
	std::list<GameStatisticObserver*> *observers; /** < List of registered GameStatisticObservers*/
};
#endif
