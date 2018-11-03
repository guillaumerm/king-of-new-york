
#include "GameMap.h"
#include "GameMapNode.h"

using namespace std;

GameMap::GameMap()
{
	vector <GameMapNode*> nodeList;
}

void GameMap::addRegion(GameMapNode* newArea)
{
	nodeList.push_back(newArea);
}

void GameMap::listAllZones()
{
	for (int i = 0; i < nodeList.size(); i++)
	{
		cout << "Zone Name: " << nodeList.at(i)->getZoneName() << endl;
	}
}

vector<GameMapNode*> GameMap::getList()
{
	return nodeList;
}

GameMapNode* GameMap::getZoneByName(string name)
{
	for (int i = 0; i < nodeList.size(); i++)
	{
		if (name == nodeList.at(i)->getZoneName())
		{
			return nodeList.at(i);
		}
	}
}

bool GameMap::adjancent(string nameSourceZone, string nameDestinationZone) {
	GameMapNode *sourceZone = this->getZoneByName(nameSourceZone);
	GameMapNode *destinationZone = this->getZoneByName(nameDestinationZone);

	return sourceZone->isAdjancent(destinationZone);
}

bool GameMap::duplicateFree()
{
	for (int i = 0; i < nodeList.size(); i++)
	{
		if (!nodeList.at(i)->duplicateAdjacentFree())
		{
			cout << "A duplicate region was found" << endl;
			return false;
		}
	}
	return true;
}

bool GameMap::allConnected()
{
	for (int i = 0; i < nodeList.size(); i++)
	{
		if (nodeList.at(i)->getNeighbours().empty())
		{
			cout << "A region is isolated" << endl;
			return false;
		}
	}
	return true;
}

//ADDED CODE
//tests if a zone exists by comparing names
bool GameMap::zoneExists(string testZone)
{
	for (int i = 0; i < nodeList.size(); i++)
	{
		if (nodeList.at(i)->getZoneName() == testZone)
		{
			return true;
		}
	}
	return false;
}

void GameMap::movePlayer(Player *player, string nameSourceZone, string nameDestinationZone) {
	GameMapNode *sourceZone = this->getZoneByName(nameSourceZone);
	GameMapNode *destinationZone = this->getZoneByName(nameDestinationZone);
	sourceZone->removePlayer(player);
	destinationZone->addPlayer(player);
}
