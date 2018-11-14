
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
	unordered_map<string, bool> *visited = new unordered_map<string, bool>();
	for (int i = 0; i < this->nodeList.size(); i++)
		visited->insert({this->nodeList.at(i)->getZoneName(), false});
	DFS(this->nodeList.at(0), visited);
	for (auto i : *visited) {
		if (!i.second)
			return false;
	}

	GameMap transposedGraph = this->getTranspose();
	visited->clear();
	for (auto i : transposedGraph.getList()) {
		visited->insert({ i->getZoneName(), false });
	}
	DFS(transposedGraph.getList().at(0), visited);
	for (auto i : *visited) {
		if (!i.second)
			return false;
	}
	return true;
}

int GameMap::getPlayersCountInManhantten()
{
	return this->getZoneByName("Lower Manhatten")->getPlayersCount() + this->getZoneByName("Midtown")->getPlayersCount() + this->getZoneByName("Upper Manhatten")->getPlayersCount();
}

void GameMap::DFS(GameMapNode* v, unordered_map<string, bool> *visited) {
	visited->insert_or_assign(v->getZoneName(), true);
	for (int i = 0; i < v->getNeighbours().size(); i++)
		if (!visited->at(v->getNeighbours().at(i)->getZoneName()))
			DFS(v->getNeighbours().at(i), visited);
}

GameMap GameMap::getTranspose() {
	GameMap transposedGraph;
	vector<GameMapNode*>::iterator i;
	for (i = this->nodeList.begin(); i != this->nodeList.end(); i++)
	{
		transposedGraph.addRegion(new GameMapNode((*i)->getZoneName()));
	}

	for (auto currentNode: this->nodeList)
	{
		for (int j = 0; j < currentNode->getNeighbours().size(); j++) {
			transposedGraph.getZoneByName(currentNode->getNeighbours().at(j)->getZoneName())->connectZones(transposedGraph.getZoneByName(currentNode->getZoneName()));
		}
	}
	return transposedGraph;
}

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
