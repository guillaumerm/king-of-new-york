#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

using namespace std;

/**
 * @brief A class which regroups the behavior/action that a GameMapNode would need to interact with game components.
 */
class Player; 

/**
 * @brief Class which regroups behavior and action 
 */
class GameMapNode {
private:
	string regionName; /**< Name of the region */
	string regionOwner; /**< Name of the owner */
	vector <GameMapNode*> adjacentZones; /**< Adjacent zone */
	vector <Player*> players; /**< Players currently in the zone */
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
	 * @param regionOwner region owners name
	 */
	GameMapNode(string regionName, string regionOwner);

	/**
	 * Get the zone name
	 * @return name of the zone
	 */
	string getZoneName() const;

	/**
	 * Get the zone owner
	 * @return name of the owner
	 */
	string getOwner() const;

	/**
	 * Get the neighbouring zones
	 * @return a vector of adjacent zones
	 */
	vector<GameMapNode*> getNeighbours();

	/**
	 * Sets a new owner
	 * @param owner new owner
	 */
	void newOwner(string owner);

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
	bool isFull();

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
};
