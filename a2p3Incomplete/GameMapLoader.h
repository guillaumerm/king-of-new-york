#pragma once
#include "GameMap.h"
#include <string>
#include <fstream>

/**
 * @brief Class used to load map files
 */
class GameMapLoader {
public:
	/**
	 * Loads a map from a given filename.
	 * @params filename filename of the map to be loaded
	 * @return GameMap pointer, NOTE: GameMap may be empty if it fails to load
	 */
	static GameMap *loadMap(string filename);
};