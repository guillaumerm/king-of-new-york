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
	 * @return GameMap pointer if map is valid, otherwiser NULL
	 */
	static GameMap *loadMap(string filename);
};