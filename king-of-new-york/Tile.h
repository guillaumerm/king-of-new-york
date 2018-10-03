#ifndef TILE_H
#define TILE_H
#include <string>

using namespace std;

class Tile {
public:
	enum Type {Unit, Building};
	Tile(string name, string description);
	bool removeDurability(int durability);
	bool isUnit() const;
private:
	bool unit;
	int durability;
	int victoryPoints;
};
#endif
