#ifndef GAME_STATISTIC_VIEW_H
#define GAME_STATISTIC_VIEW_H

#include <iostream>
#include <map>
#include <string>
#include "GameStatisticInterface.h"
#include "GameStatisticObserver.h"
class GameStatisticView : public GameStatisticInterface, public GameStatisticObserver {
public:
	void update(std::string playerName, std::string location, int victoryPoints);
	void show();
private:
	std::map<std::string, std::string> playerLocation;
	std::map<std::string, int> playerProgression;
};
#endif
