#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <vector>
#include "Node.h"

using namespace std;

class Map {
private:
	vector <Node*> nodeList;
public:
	
	Map();
	
	void addRegion(Node* newArea);
	void listAllZones();
	vector<Node*> getList();
	Node* getZoneByName(string);
};

#endif