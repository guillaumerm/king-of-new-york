#include "InteractiveMovingStrategy.h"
#include "Util.h"

void InteractiveMovingStrategy::execute(Player * player, GameMap * map) {
	GameMapNode* currentZone = map->getZoneByName(player->getCurrentZone());
	vector<GameMapNode*> neighbours = currentZone->getNeighbours();

	if (currentZone->getZoneName() == "Upper Manhatten") {
		cout << "Since you are in Upper Manhatten you need to stay there." << endl;
		player->endPhase();
	}
	else if (neighbours.size() == 1) {
		cout << "Since you were in " << player->getCurrentZone() << " you were moved to " << neighbours.at(0)->getZoneName() << endl;
		player->move(map, neighbours.at(0)->getZoneName());
		player->endPhase();
	}
	else {
		cout << "List of possible zones:" << endl;
		for (int i = 0; i < neighbours.size(); i++) {
			cout << (i + 1) << ")" << neighbours.at(i)->getZoneName() << endl;
		}
		int choice = askChoiceQuestion("Select which zone you want to move to? (0 to skip this phase)", 0, neighbours.size());
		if (choice != 0) {
			player->move(map, neighbours.at(choice - 1)->getZoneName());
			player->endPhase();
		}
		else {
			player->endPhase();
		}
	}
}
