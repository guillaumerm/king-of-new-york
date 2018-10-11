#include "GameMapNode.h"

using namespace std;

const int NUMBER_OF_PLAYER_SLOTS = 2;

string const defaultRegion = "";
string const defaultOwner = "";
vector <GameMapNode*> adjacentZones;

GameMapNode::GameMapNode() :GameMapNode(defaultRegion, defaultOwner) {};

GameMapNode::GameMapNode(string region)
{
	regionName = region;
	regionOwner = "None";
}

GameMapNode::GameMapNode(string region, string initialOwner)
{
	regionName = region;
	regionOwner = initialOwner;
}

string GameMapNode::getZoneName() const
{
	return regionName;
}

string GameMapNode::getOwner() const
{
	return this->regionOwner;
}

void GameMapNode::newOwner(string usurper)
{
	regionOwner = usurper;
}

void GameMapNode::connectZones(GameMapNode* adjacentZone)
{
	//connectZones is called by one of the GameMapNodes and the other as its parameter
	//connectZones adds both zones into each other's respective adjacentZone list
	adjacentZones.push_back(adjacentZone);
	adjacentZone->adjacentZones.push_back(this);
}

void GameMapNode::printNeighbours()
{
	if (adjacentZones.empty())
	{
		cout << "This region has no neighbours." << endl;
	}
	else
	{
		cout << regionName << " has ";
		for (int i = 0; i < adjacentZones.size(); i++)
		{
			cout << adjacentZones.at(i)->getZoneName() << ", ";
		}
		cout << "as its adjacent regions." << endl;
	}
}

bool GameMapNode::isAdjancent(GameMapNode *adjancentGameMapNode) {
	vector<GameMapNode *>::iterator iteratorAdjacentGameMapNode = adjacentZones.begin();
	while (iteratorAdjacentGameMapNode < adjacentZones.end()) {
		if (*iteratorAdjacentGameMapNode == adjancentGameMapNode) {
			return true;
		}
		iteratorAdjacentGameMapNode++;
	}
	return false;
}

bool GameMapNode::isFull() {
	return this->players.size() < NUMBER_OF_PLAYER_SLOTS;
}

void GameMapNode::addPlayer(Player *player) {
	if (!this->players.empty()) {
		int idx = 0;

		while (idx < NUMBER_OF_PLAYER_SLOTS && player != this->players.at(idx)) {
			idx++;
		}

		if (player != this->players.at(idx)) {
			this->players.push_back(player);
		}
	}
}

void GameMapNode::removePlayer(Player *player) {
	if (!this->players.empty()) {
		int idx = 0;

		while (idx < NUMBER_OF_PLAYER_SLOTS && player != this->players.at(idx)) {
			idx++;
		}

		if (player == this->players.at(idx)) {
			this->players.erase(this->players.begin() + idx);
		}
	}
}