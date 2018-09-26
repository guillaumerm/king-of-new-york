#ifndef TILE_H
#define TILE_H
#include <string>

using namespace std;

class Tile {
public:
	Tile(string name, string description);
	bool removeDurability(int durability);
	bool isUnit() const;
private:
	bool unit;
	int durability;
	int victoryPoints;
};
#endif
