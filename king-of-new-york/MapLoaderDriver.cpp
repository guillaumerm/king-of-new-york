#include "GameMapLoader.h"
#include "GameMap.h"

int main() {
	GameMap *invalidMap = GameMapLoader::loadMap("invalid.map");
	if (invalidMap != NULL) {
		cout << "Should not reach this code" << endl;
	}
	GameMap *validMap = GameMapLoader::loadMap("new_york.map");
	if (validMap == NULL) {
		cout << "Should not reach this code" << endl;
	}
	else {
		cout << "Map is valid" << endl;
	}
	system("pause");
	return 0;
}