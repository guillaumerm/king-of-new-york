#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "GameMapNode.h"

using namespace std;

class Player;
class GameMapNode;
/** 
 * @brief A class which regroups behavior and actions used by the GameMap to interact with other game components.
 */
class GameMap {
private:
	vector <GameMapNode *> nodeList; /**< Lists of zones*/
	static void DFS(GameMapNode *v, unordered_map<string, bool>* visited);
	GameMap getTranspose();
public:
	/**
	 * Parameterless constructor
	 */
	GameMap();
	/**
	 * Add a GameMapNode * to the GameMap
	 * @param newArea new zone to be added to the map
	 */
	void addRegion(GameMapNode* newArea);

	/**
	 * Prints out all zones.
	 */
	void listAllZones();

	/**
	 * Get the list of zones in the GameMap
	 * @return vector<GameMapNode *> of zones in the GameMap
	 */
	vector<GameMapNode*> getList();

	/**
	 * Searches for the zone with the name
	 * @param nameZone name of the zone to be searched
	 * @return the zone if found, null otherwise
	 */
	GameMapNode* getZoneByName(string nameZone);

	/**
	 * Checks whether two given zone are adjancent
	 * @param nameZone1 name of the first zone
	 * @param nameZone2 name of the second zone
	 * @return true if the zones are adjancent, false otherwise
	 */
	bool adjancent(string nameZone1, string nameZone2);

	/**
	 * Checks whether there is no duplicate zones or edges
	 * @return true if the duplicate free, false otherwise
	 */
	bool duplicateFree();

	/**
	 * Checks whether the map is connected
	 * @return true if connected, false otherwise
	 */
	bool allConnected();

	/**
	 * Moves a player from one zone to another.
	 * @param player the player to be moved
	 * @param origin the current zone of the player
	 * @param destination the destination zone of the player
	 */
	void movePlayer(Player *player, string origin, string destination);

	/**
	 * Verifies that a zone exists.
	 * @param testZone the name of the zone
	 * @return true if the zone exists, false otherwise
	 */
	bool zoneExists(string testZone);
};