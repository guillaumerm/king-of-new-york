#ifndef TILE_H
#define TILE_H
#include <string>

using namespace std;

/**
 * @brief A tile which is used to create Unit and Building.
 */
class Tile {
public:
	enum Type {
		Unit, /**< Unit type of tiles */
		Building /**< Building type of tiles */
	};

	/** 
	 * A constructor which init a tile with a name, description and durability
	 * @param name name of the tile
	 * @param description description of the tile
	 * @param durability durability of the tile
	 */
	Tile(string name, string description, int durability);

	/**
	 * A constructor which init a tile with a name, description and durability
	 * @param name name of the tile
	 * @param description description of the tile
	 * @param durability durability of the tile
	 * @param type Tile::Type of the tile
	 */
	Tile(string name, string description, int durability, Tile::Type type);

	/**
	 * Changes the type of the tile if the durability removed is equal to the tile durability
	 * @param durability durability to be removed
	 */
	void removeDurability(int durability);

	/**
	 * Obtain the current type of the tile
	 * @return Tile::Type of the card
	 */
	Tile::Type getType() const;

	/**
	 * Obtain the name of the tile
	 * @return name of the card
	 */
	string getName() const;

	/**
	 * Obtain the description of the tile
	 * @return description of the card
	 */
	string getDescription() const;
	
	/**
	 * Obtain the durability of the tile
	 * @return durability of the card
	 */
	int getDurability() const;

	/**
	 * Checks whether a tile is a Tile::Type::Building
	 * @return true if tile is of tyep Tile::Type::Building
	 */
	bool isBuilding() const;

	/**
	 * Checks whether a tile is a Tile::Type::Unit
	 * @return true if tile is of tyep Tile::Type::Unit
	 */
	bool isUnit() const;
private:
	Tile::Type type; /**< Type of the tile */
	string name; /**< Name of the card */
	string description; /**< Description of the card */
	int durability; /**< Durability of the card */

	/**
	 * Sets the name of the tile
	 * @param name name of the card
	 */
	void setName(string name);

	/**
	 * Sets the description of the tile
	 * @param description description of the card
	 */
	void setDescription(string name);

	/**
	 * Sets the durability of the tile
	 * @param durability durability of the card
	 */
	void setDurability(int durability);

	/**
	 * Sets the Tile::Type of the tile
	 * @param type type of the card
	 */
	void setType(Tile::Type type);
};
#endif
