#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Tile.h"
#include "Subject.h"

using namespace std;

/**
 * @brief A class which regroups the behavior/action that a GameMapNode would need to interact with game components.
 */
class Player; 

/**
 * @brief Class which regroups behavior and action 
 */
class GameMapNode : public Subject {
private:
	string regionName; /**< Name of the region */
	bool startingZone; /**< Zone a starting zone */
	vector <GameMapNode*> adjacentZones; /**< Adjacent zone */
	vector <Player*> players; /**< Players currently in the zone */
	Tile * tileStack[5][3];
public:
	/**
	 * Parameterless constructor
	 */
	GameMapNode();

	/**
	 * A constructor which init a GameMapNode with a region name
	 * @param regionName region name of the zone
	 */
	GameMapNode(string regionName);

	/**
	 * A constructor which init a GameMapNode with a region name and owners name
	 * @param regionName region name of the zone
	 * @param startingZone if zone is a startingZone
	 */
	GameMapNode(string regionName, bool startingZone);

	/**
	 * Get the zone name
	 * @return name of the zone
	 */
	string getZoneName() const;

	/**
	 * Verifies that the zone is a not starting zone.
	 * @return true if its not a starting zone, false otherwise
	 */
	void noStartHere();

	/**
	 * Used to set a player
	 * @return true
	 */
	bool setPlayerStart(Player* playerStart);

	/**
	 * Get the count of players currently in the zone
	 * @return number of player currently in the zone
	 */
	int getPlayersCount() const;

	/**
	 * Returns if the zone is a starting zone
	 * @return true if starting zone, false otherwise
	 */
	bool isStartZone() const;

	/**
	 * Get the neighbouring zones
	 * @return a vector of adjacent zones
	 */
	vector<GameMapNode*> getNeighbours();

	/**
	 * Connects zones
	 * @param zone zone to connect to
	 */
	void connectZones(GameMapNode *zone);

	/**
	 * Prints the adjacent zones
	 */
	void printNeighbours();

	/**
	 * Checks if a GameMapNode is adjancent
	 * @param zone zone to be check if adjancent
	 * @return true if adjacent, false otherwise
	 */
	bool isAdjancent(GameMapNode *zone);


	bool duplicateAdjacentFree();
	
	/**
	 * Checks if a GameMapNode has place for players
	 * @return true if no more space, false otherwise
	 */
	bool isNotFull();

	/**
	 * Adds a player to the zone
	 * @param player to be added to the zone
	 */
	void addPlayer(Player *player);

	/**
	 * Removes a player from the zone
	 * @param player to be remove from the zone
	 */
	void removePlayer(Player *);

	/**
	 * Adds a tile to a stack
	 * @param outterIndex the index of the stack
	 * @param innerIndex the index of the location you are adding the tile
	 * @param newTile the tile being added to the stack
	 */
	void addTileToStack(int outterIndex, int innerIndex, Tile* newTile);

	vector<Player*> getPlayers();
};
