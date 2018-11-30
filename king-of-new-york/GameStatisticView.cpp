#include "GameStatisticView.h"

void GameStatisticView::update(std::string playerName, std::string location, int victoryPoints, int healPoints, int energyCubes)
{
	std::map<std::string, std::string>::iterator currentPlayerLocation = this->playerLocation.find(playerName);
	if (currentPlayerLocation != this->playerLocation.end()) {
		currentPlayerLocation->second = location;
	}
	else {
		this->playerLocation.emplace(playerName, location);
	}

	std::map<std::string, int>::iterator currentPlayerProgression = this->playerProgression.find(playerName);
	if (currentPlayerProgression != this->playerProgression.end()) {
		currentPlayerProgression->second = victoryPoints;
	} 
	else {
		this->playerProgression.insert_or_assign(playerName, victoryPoints);
	}

	std::map<std::string, int>::iterator currentPlayerHealPoints = this->playerHealthPoints.find(playerName);
	if (currentPlayerHealPoints != this->playerHealthPoints.end()) {
		currentPlayerHealPoints->second = healPoints;
	}
	else {
		this->playerHealthPoints.emplace(playerName, healPoints);
	}

	std::map<std::string, int>::iterator currentEnergyCubes = this->playerEnergyCubes.find(playerName);
	if (currentEnergyCubes != this->playerEnergyCubes.end()) {
		currentEnergyCubes->second = energyCubes;
	}
	else {
		this->playerEnergyCubes.emplace(playerName, energyCubes);
	}
}

void GameStatisticView::show() {
	char square = 254;
	std::cout << "------------ Current Statistics ------------" << std::endl;
	for (auto player : this->playerLocation) {
		std::cout << square << " " << player.first << " is located in " << player.second << " and has currently ";
		std::map<std::string, int>::iterator currentProgression = this->playerProgression.find(player.first);

		if (currentProgression != this->playerProgression.end()) {
			std::cout << std::to_string(currentProgression->second) << " Points ";
		}
		else {
			std::cout << std::to_string(0) << " Points ";
		}

		std::map<std::string, int>::iterator currentHealPoints = this->playerHealthPoints.find(player.first);

		if (currentHealPoints != this->playerHealthPoints.end()) {
			std::cout << std::to_string(currentHealPoints->second) << " Health Points ";
		}
		else {
			std::cout << std::to_string(0) << " Health Points ";
		}

		std::map<std::string, int>::iterator currentEnergyCubes = this->playerEnergyCubes.find(player.first);

		if (currentEnergyCubes != this->playerEnergyCubes.end()) {
			std::cout << std::to_string(currentEnergyCubes->second) << " EnergyCubes ";
		}
		else {
			std::cout << std::to_string(0) << " EnergyCubes ";
		}
		std::cout << std::endl;
	}

	std::cout << "------------ End Current Statistics ------------" << std::endl;
}
