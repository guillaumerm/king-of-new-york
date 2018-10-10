#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <string>
#include <vector>
#include "Player.h"

using namespace std;

class Node {
private:
	string regionName;
	string regionOwner;
	vector <Node*> adjacentZones;
	vector <Player*> players;
public:
	Node();
	Node(string);
	Node(string, string);

	string getZoneName() const;
	string getOwner() const;
	void newOwner(string);
	void connectZones(Node*);
	void printNeighbours();
	bool isAdjancent(Node *);
	bool isFull();
	void addPlayer(Player *);
	void removePlayer(Player *);
};

#endif