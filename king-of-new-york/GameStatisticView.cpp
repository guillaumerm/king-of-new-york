#include "GameStatisticView.h"

void GameStatisticView::update(std::string playerName, std::string location, int victoryPoints)
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
}

void GameStatisticView::show() {
	char square = 254;
	std::cout << "------------ Current Statistics ------------" << std::endl;
	for (auto player : this->playerLocation) {
		std::cout << square << " " << player.first << " is located in " << player.second << " and has currently ";
		std::map<std::string, int>::iterator currentProgression = this->playerProgression.find(player.first);

		if (currentProgression != this->playerProgression.end()) {
			std::cout << std::to_string(currentProgression->second);
		}
		else {
			std::cout << std::to_string(0);
		}
		std::cout << std::endl;
	}

	std::cout << "------------ End Current Statistics ------------" << std::endl;
}
