#ifndef TILE_H
#define TILE_H
#include <string>

using namespace std;

class Tile {
public:
	enum Type {Unit, Building, Destroyed};
	Tile(string name, string description, int durability);
	Tile(string name, string description, int durability, Tile::Type type);
	void removeDurability(int durability);
	Tile::Type getType() const;
	string getName() const;
	string getDescription() const;
	int getDurability() const;
	bool isBuilding() const;
	bool isUnit() const;
	bool isDestroy() const;
private:
	Tile::Type type;
	string name;
	string description;
	int durability;
	bool unit;
	void setName(string);
	void setDescription(string);
	void setDurability(int);
	void setType(Tile::Type type);
	int durability;
	int victoryPoints;
};
#endif
