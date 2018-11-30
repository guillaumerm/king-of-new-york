#ifndef GAME_STATISTIC_VIEW_H
#define GAME_STATISTIC_VIEW_H

#include <iostream>
#include <map>
#include <string>
#include "GameStatisticInterface.h"
#include "GameStatisticObserver.h"

/**
 * @brief A view which is used to keep track GameStatistic.
 */
class GameStatisticView : public GameStatisticInterface, public GameStatisticObserver {
public:
	/**
	 * Method used by GameStatisticSubject to notify the view that a change as occured.
	 * @param playerName name of the subject
	 * @param location current location of the subject
	 * @param victoryPoints current number of victory points being held by the player
	 * @param healPoints current number of heal points that a player has
	 * @param energyCubes current number of energy cubes held by the player
	 */
	void update(std::string playerName, std::string location, int victoryPoints, int healPoints, int energyCubes);

	/**
	 * Method used to display the current GameStatistic.
	 */
	void show();
private:
	std::map<std::string, std::string> playerLocation; /** < Current location of the players */
	std::map<std::string, int> playerProgression;/** < Current progression of the players */
	std::map<std::string, int> playerHealthPoints; /** < Current heal points of the players */
	std::map<std::string, int> playerEnergyCubes; /** < Current energy cubes of the players */
};
#endif
