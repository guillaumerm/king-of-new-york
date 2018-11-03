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

using namespace std;

int main() {

		cout << "Welcome to the King of New York game!" << endl;
		cout << "This driver will set up the New York map and create a game for 4 players." << endl;

		GameMap map = *GameMapLoader::loadMap("MapDirectory/new_york.map");
		map.listAllZones();
		
		//Restricting some zones from being where the players can start the game at
		/*for (int i = 0; i < 3; i++)
		{
			map.getList().at(i)->noStartHere();//FUNCTION CAUSES RUNTIME ERRROR
		}*/

		vector <Player*> playerList;
		MonsterCard* monsterList = initMonsterCards();
		for (int i = 0; i < 4; i++)
		{
			Player * autoPlayer = new Player(&monsterList[i]);
			playerList.push_back(autoPlayer);
		}

		for (int i = 0; i < playerList.size(); i++)
		{
			cout << "Player " << i + 1 << " will be playing as: " << playerList.at(i)->getMonster() << endl;
		}
		cout << "To decide the turn order, all players will roll the dice and the one with most Attack shall go first" << endl;
		int mostAttack = -1;
		int currentAttack = -1;
		int indOfMostAttack = -1;
		for (int i = 0; i < playerList.size(); i++)
		{
			const DiceRoll *diceRoll = playerList.at(i)->rollDice(8);
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
				indOfMostAttack -= 4;
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

		cout << "Now players will choose which boroughs they'd like to begin in" << endl;

		bool undecidedStart;
		string chosenZone;
		for (int i = 0; i < 4; i++)
		{
			undecidedStart = true;
			while (undecidedStart)
			{
				cout << "Player " << turnOrder[i] + 1 << ", please choose your starting zone" << endl;
				getline(cin, chosenZone);

				if (map.zoneExists(chosenZone))
				{
					if (map.getZoneByName(chosenZone)->isNotFull() && map.getZoneByName(chosenZone)->setPlayerStart(playerList.at(turnOrder[i])))
					{
						undecidedStart = false;
					}
					else if (!map.getZoneByName(chosenZone)->isNotFull())
					{
						cout << "Sorry that zone is full. Please choose another" << endl;
					}
				}
				else
				{
					cout << "Sorry that zone doesn't exist" << endl;
				}
			}
		}

		cout << "Preparing the remaining game pieces..." << endl;
		initTokens(13, 13, 5, 15);
		cout << "Tokens ready..." << endl;
		vector <Tile*> tileStack;
		for (int x = 0; x < map.getList().size(); x++)
		{
			//One stack of 3 tiles per zone in Manhatten
			if (x < 3)
			{
				for (int i = 0; i < 3; i++)
				{
					Tile* newTile = new Tile("Building", "A Generic Building", 1);
					map.getList().at(x)->addTileToStack(0, i, newTile);
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
						map.getList().at(x)->addTileToStack(i, j, newTile);
						//cout << "Tile added to: " << map.getList().at(x)->getZoneName() << endl;
					}
				}
			}
		}
		cout << "Tiles have been placed..." << endl;
		cout << "Game Ready To Start!" << endl;

		bool unfinishedGame = true;
		int endGame = 0;
		while (unfinishedGame)
		{
			//Roll phase
			for (int i = 0; i < playerList.size(); i++)
			{
				cout << "Player " << turnOrder[i] + 1<< " is rolling" << endl;
				playerList.at(turnOrder[i])->startTurn();
				cout << "Player " << turnOrder[i] + 1 << " is resolving" << endl;
				executeRollDicePhase(*playerList.at(turnOrder[i]), 6);
				cout << "Player " << turnOrder[i] + 1 << " is resolving" << endl;
				executeResolveDicePhase(*playerList.at(turnOrder[i]));
				cout << "Player " << turnOrder[i] + 1 << " is asked to move" << endl;
				executeMovePhase(playerList.at(turnOrder[i]), &map);
				cout << "Move finished" << endl;
				playerList.at(turnOrder[i])->endTurn();
			}
			
			for (int i = 0; i < playerList.size(); i++)
			{
				if (playerList.at(i)->getVictoryPoints() >= 20)
				{
					cout << playerList.at(i)->getMonster() << " has obtained 20 victory points!" << endl;
					cout << "Player " << i + 1 << " wins!" << endl;
					unfinishedGame = false;
				}
			}
			//ALTERNATIVE WAY TO END PROGRAM (FOR TESTING)
			endGame++;
			if (endGame == 3)
			{
				unfinishedGame = false;
			}
		}

	return 0;
}