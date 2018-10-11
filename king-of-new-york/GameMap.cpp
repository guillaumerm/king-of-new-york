
#include "GameMap.h"
#include "GameMapNode.h"

using namespace std;

vector <GameMapNode*> nodeList;

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
		cout << "Zone Name: " << nodeList.at(i)->getZoneName() << "; and is owned by: " << nodeList.at(i)->getOwner() << endl;
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

void GameMap::movePlayer(Player *player, string nameSourceZone, string nameDestinationZone) {
	GameMapNode *sourceZone = this->getZoneByName(nameSourceZone);
	GameMapNode *destinationZone = this->getZoneByName(nameDestinationZone);
	sourceZone->removePlayer(player);
	destinationZone->addPlayer(player);
}