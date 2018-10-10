#include <stdio.h>
#include <vector>
#include <iostream>
#include "Node.h"

#include "Map.h"

using namespace std;

vector <Node*> nodeList;

Map::Map()
{
	vector <Node*> nodeList;
}

void Map::addRegion(Node* newArea)
{
	nodeList.push_back(newArea);
}

void Map::listAllZones()
{
	for (int i = 0; i < nodeList.size(); i++)
	{
		cout << "Zone Name: " << nodeList.at(i)->getZoneName() << "; and is owned by: " << nodeList.at(i)->getOwner() << endl;
	}
}

vector<Node*> Map::getList()
{
	return nodeList;
}

Node* Map::getZoneByName(string name)
{
	for (int i = 0; i < nodeList.size(); i++)
	{
		if (name == nodeList.at(i)->getZoneName())
		{
			return nodeList.at(i);
		}
	}
}

bool Map::adjancent(string nameSourceZone, string nameDestinationZone) {
	Node *sourceZone = this->getZoneByName(nameSourceZone);
	Node *destinationZone = this->getZoneByName(nameDestinationZone);
	
	return sourceZone->isAdjancent(destinationZone);
}

void Map::movePlayer(Player *player, string nameSourceZone, string nameDestinationZone) {
	Node *sourceZone = this->getZoneByName(nameSourceZone);
	Node *destinationZone = this->getZoneByName(nameDestinationZone);
	sourceZone->removePlayer(player);
	destinationZone->addPlayer(player);
}
