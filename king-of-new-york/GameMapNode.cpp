#include "GameMapNode.h"

using namespace std;

const int NUMBER_OF_PLAYER_SLOTS = 2;

string const defaultRegion = "";
string const defaultOwner = "";
vector <GameMapNode*> adjacentZones;

GameMapNode::GameMapNode() :GameMapNode(defaultRegion, true) {};

GameMapNode::GameMapNode(string region):GameMapNode(region, true){}

GameMapNode::GameMapNode(string region, bool startZoneStatus)
{
	regionName = region;
	startingZone = startZoneStatus;
}

string GameMapNode::getZoneName() const
{
	return regionName;
}

vector<GameMapNode*> GameMapNode::getNeighbours()
{
	return this->adjacentZones;
}

void GameMapNode::connectZones(GameMapNode* adjacentZone)
{
	//connectZones is called by one of the GameMapNodes and the other as its parameter
	//connectZones adds both zones into each other's respective adjacentZone list
	adjacentZones.push_back(adjacentZone);
	//adjacentZone->adjacentZones.push_back(this);
}

int GameMapNode::getPlayersCount() const{
	return this->players.size();
}

vector<Player*> GameMapNode::getPlayers()
{
	return this->players;
}

bool GameMapNode::isStartZone() const
{
	return this->startingZone;
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

bool GameMapNode::duplicateAdjacentFree()
{
	for (int i = 0; i < adjacentZones.size(); i++)
	{
		for (int j = i + 1; j < adjacentZones.size(); j++)
		{
			if (adjacentZones.at(i)->getZoneName() == adjacentZones.at(j)->getZoneName())
			{
				return false;
			}
		}

	}
	return true;
}

bool GameMapNode::isNotFull() {
	return this->players.size() < NUMBER_OF_PLAYER_SLOTS;
}

void GameMapNode::noStartHere()
{
	startingZone = false;
	cout << regionName << " is not a starting zone" << endl;
}


bool GameMapNode::setPlayerStart(Player* playerStart)
{
	if (startingZone)
	{
		playerStart->setCurrentZone(this->getZoneName());
		addPlayer(playerStart);
		return true;
	}
	else
	{
		cout << "Sorry this zone is not for players to start at" << endl;
		return false;
	}

}

void GameMapNode::addPlayer(Player *player) {
	if (!this->players.empty() && isNotFull()) {
		if (player != this->players.at(0)) {
			this->players.push_back(player);
			//cout << "Player added to " << getZoneName() << endl;
		}
	}
	else
	{
		this->players.push_back(player);
		//cout << "Player added to " << getZoneName() << endl;
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

void GameMapNode::addTileToStack(int outterIndex, int innerIndex, Tile* newTile)
{
	tileStack[outterIndex][innerIndex] = newTile;
}
