#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "GameMapNode.h"

using namespace std;

class Player;
class GameMapNode;

class GameMap {
private:
	vector <GameMapNode *> nodeList;
public:

	GameMap();

	void addRegion(GameMapNode* newArea);
	void listAllZones();
	vector<GameMapNode*> getList();
	GameMapNode* getZoneByName(string);
	bool adjancent(string, string);
	void movePlayer(Player *, string, string);
};