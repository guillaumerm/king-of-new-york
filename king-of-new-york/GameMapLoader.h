#pragma once
#include "GameMap.h"
#include <string>
#include <fstream>

class GameMapLoader {
public:
	static GameMap *loadMap(string);
};