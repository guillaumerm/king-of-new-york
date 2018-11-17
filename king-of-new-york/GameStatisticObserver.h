#ifndef GAME_STATISTIC_OBSERVER_H
#define GAME_STATISTIC_OBSERVER_H
#include <string>

class GameStatisticObserver {
public:
	virtual void update(std::string playerName, std::string location, int victoryPoints) = 0;
};
#endif
