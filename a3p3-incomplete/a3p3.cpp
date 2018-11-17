#include <stdio.h>
#include <iostream>
#include <vector>

#include "GameManager.h"
#include "Player.h"
#include "PlayerStateMachine.h"
#include "GameMapLoader.h"
#include "GameMap.h"
#include "PieceManager.h"
#include "Tile.h"
#include "Deck.h"
#include "PlayerStrategyDirector.h"
#include "InteractivePlayerStrategyBuilder.h"
#include "ListWatcher.h"

using namespace std;

/**
 * Verifies if any of the player has won.
 * @param playerList the playerList
 * @return winning player, otherwise NULL
 */
Player *hasWon(vector<Player *>* playerList) {
	vector<Player *>::iterator curPlayer;
	int dead = 0;
	Player * lastALife = NULL;
	for (curPlayer = playerList->begin(); curPlayer != playerList->end(); curPlayer++) {
		if ((*curPlayer)->isDead()) {
			dead++;
		}
		else if ((*curPlayer)->getVictoryPoints() == 20) {
			return *curPlayer;
		}
		else {
			lastALife = *curPlayer;
		}
	}

	if (dead == playerList->size() - 1) {
		return lastALife;
	}

	return NULL;
}

int main() {

	cout << "Welcome to the King of New York game!" << endl;
	cout << "This driver will set up the New York map and create a game for 4 players." << endl;
	cout << endl << endl << "[1] Start Phase" << endl << endl << endl;

	string mapName = "..\\king-of-new-york\\MapDirectory\\new_york.map";
	GameMap* map = GameMapLoader::loadMap(mapName);
	GameManager *manager = new GameManager();

	vector<Player*>* playerList = new vector<Player*>();
	Deck<GameCard*>* deckOfCards = new Deck<GameCard*>(64);

	int playCount = 4;

	cout << "Preparing the game for " << playCount << " players...." << endl;
	MonsterCard* monsterList = initMonsterCards();

	int monsterChoice = 0;
	//for loop for player creation
	for (int i = 0; i < playCount; i++)
	{
		Player * newPlayer = new Player(&monsterList[monsterChoice], NULL);
		playerList->push_back(newPlayer);
		monsterChoice++;
	}
	deckOfCards = initDeck();

	InteractivePlayerStrategyBuilder *inpsb = new InteractivePlayerStrategyBuilder();

	PlayerStrategyDirector psd;
	psd.setPlayerStrategyBuilder(inpsb);

	for (auto iter : *playerList) {
		iter->attach(manager);
		
		psd.constructPlayerStrategy();
		iter->setPlayerStrategy(psd.getPlayerStrategy());
	}
	
	vector<GameCard*> cardsAvailable;
	cardsAvailable.push_back(*deckOfCards->deal());
	cardsAvailable.push_back(*deckOfCards->deal());
	cardsAvailable.push_back(*deckOfCards->deal());

	cout << endl << endl << "[2] Start Up Phase" << endl << endl << endl;

	cout << "To decide the turn order, all players will roll the dice and the one with most Attack shall go first" << endl;
	int mostAttack = -1;
	int currentAttack = -1;
	int indOfMostAttack = -1;
	for (int i = 0; i < playerList->size(); i++)
	{
		const DiceRoll *diceRoll = playerList->at(i)->rollDice(8);
		currentAttack = diceRoll->getSumAttack();
		cout << "Player " << i + 1 << " rolled " << currentAttack << " attack faces" << endl;
		//In the event of 2 or more players roll the same number of attack then the player who rolled first wins
		if (currentAttack > mostAttack)
		{
			mostAttack = currentAttack;
			indOfMostAttack = i;
		}

	}
	int * turnOrder = new int[4];
	cout << "Player with the most attack faces: " << indOfMostAttack + 1 << endl;
	turnOrder[0] = indOfMostAttack;
	indOfMostAttack++;
	//cout << turnOrder[0] << " " << endl;
	for (int i = 1; i < 4; i++)
	{
		if (indOfMostAttack + 1 > 4)
		{
			indOfMostAttack -= playerList->size();
			turnOrder[i] = indOfMostAttack;
		}
		turnOrder[i] = indOfMostAttack;
		indOfMostAttack++;
		//cout << turnOrder[i] << " " << endl;
	}
	//NOTE: For simplicity "clockwise order" will be assumed to be in the order players were created
	cout << "Therefore the turn order is:" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "Player " << turnOrder[i] + 1 << " is " << i + 1 << "(st/nd/rd/th)" << endl;
	}

	map->getZoneByName("Bronx")->setPlayerStart(playerList->at(turnOrder[0]));
	map->getZoneByName("Queens")->setPlayerStart(playerList->at(turnOrder[1]));
	map->getZoneByName("Brooklyn")->setPlayerStart(playerList->at(turnOrder[2]));
	map->getZoneByName("Staten Island")->setPlayerStart(playerList->at(turnOrder[3]));

	//cout << "Preparing the remaining game pieces..." << endl;
	initTokens(13, 13, 5, 15);
	//cout << "Tokens ready..." << endl;
	vector <Tile*> tileStack;
	for (int x = 0; x < map->getList().size(); x++)
	{
		//One stack of 3 tiles per zone in Manhatten
		if (x < 3)
		{
			for (int i = 0; i < 3; i++)
			{
				Tile* newTile = new Tile("Building", "A Generic Building", 1);
				map->getList().at(x)->addTileToStack(0, i, newTile);
				//cout << "Tile added to: " << map.getList().at(x)->getZoneName() << endl;
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Tile* newTile = new Tile("Building", "A Generic Building", 1);
					map->getList().at(x)->addTileToStack(i, j, newTile);
					//cout << "Tile added to: " << map.getList().at(x)->getZoneName() << endl;
				}
			}
		}
	}
	//cout << "Tiles have been placed..." << endl;
	
	ListWatcher *watcher = new ListWatcher();
	for (int i = 0; i < map->getList().size(); i++)
	{
		GameMapNode * zone = map->getList().at(i);
		cout << zone->getZoneName();
		zone->attach(watcher);
	}

	cout << "Game Ready!" << endl;
	
	cout << endl << endl << "[3] Main Game Loop" << endl << endl << endl;

	Player* winningPlayer;
	// Main game loop - play until someone wins
	while (!(winningPlayer = hasWon(playerList))) {
		for (int turn = 0; turn < playerList->size(); turn++) {
			cout << "--Player " << turnOrder[turn] + 1 << " turn--" << endl;
			Player* curPlayer = playerList->at(turnOrder[turn]);
			manager->currentPlayer = curPlayer;
			// Precondition of playing a turn the player must not be dead
			if (curPlayer->isDead()) {
				continue;
			}
			curPlayer->startTurn();
			curPlayer->executeTurn(map, cardsAvailable, 6);
			map->getZoneByName(curPlayer->getCurrentZone())->notify();
			curPlayer->endTurn();
		}
		// Line to accelerate to the winning condition
		playerList->at(0)->addVictoryPoints(10);
	}

	cout << winningPlayer->getMonster() << " has won the game" << endl;
	return 0;
}