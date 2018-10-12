#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

using namespace std;

class Player; 

class GameMapNode {
private:
	string regionName;
	string regionOwner;
	vector <GameMapNode*> adjacentZones;
	vector <Player*> players;
public:
	GameMapNode();
	GameMapNode(string);
	GameMapNode(string, string);

	string getZoneName() const;
	string getOwner() const;
	vector<GameMapNode*> getNeighbours();
	void newOwner(string);
	void connectZones(GameMapNode*);
	void printNeighbours();
	bool isAdjancent(GameMapNode *);
	bool duplicateAdjacentFree();
	bool isFull();
	void addPlayer(Player *);
	void removePlayer(Player *);
};
