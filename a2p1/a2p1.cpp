#include <stdio.h>
#include <istream>
#include <vector>
#include <algorithm>

#include "GameMapLoader.h"
#include "GameMap.h"
#include "Player.h"
#include "PieceManager.h"

using namespace std;

template <class T> void printArray(T* array, int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << endl;
	}
	cout << endl;
}

int main()
{
	cout << "Welcome to the King of New York game!" << endl;
	cout << "To begin, a map file must be loaded from your \"Map Directory\" " << endl;
	bool invalidMap = true;
	string mapName;
	GameMap newMap = GameMap::GameMap();

	//while loop to choose map to be loaded
	while (invalidMap)
	{
		cout << "Please enter a map file: ";
		cin >> mapName;
		mapName = "MapDirectory\\" + mapName;
		cout << "Your given map was: " << mapName << endl;
		newMap = * GameMapLoader::loadMap(mapName);
		if (!newMap.getList().empty())
		{
			if (newMap.duplicateFree() && newMap.allConnected())
			{
				cout << "Valid map loaded to play!" << endl;
				newMap.listAllZones();

				for (int i = 0; i < newMap.getList().size(); i++)
				{
					newMap.getList().at(i)->printNeighbours();
				}
				invalidMap = false;
			}
			else
			{
				cout << "Invalid map file. Please try another within the directory." << endl;
			}
		}
		else
		{
			cout << "Sorry that map was not found. Check your map directory for valid maps" << endl;
		}
	}

	cout << "Next, please enter the number of players for the game. (2-6)." << endl;
	int playCount = -1;
	while (playCount < 2 || playCount > 6)
	{
		cout << "Please enter an integer between 2 and 6: ";
		playCount = -1;
		while (!(cin >> playCount))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter an integer between 2 and 6: ";
		}
	}
	cout << "Preparing the game for " << playCount << " players...." << endl;
	vector <Player*> playerList;
	MonsterCard* monsterList = initMonsterCards();
	cout << "Monster card options are the following:" << endl;
	int monsterChoice = -1;
	int chosenMonster[] = {0,1,2,3,4,5};
	int * validChoice;
	printArray<MonsterCard>(monsterList, 6);
	
	//for loop for player creation
	for (int i = 0; i < playCount; i++)
	{
		while (monsterChoice < 0 || monsterChoice > 5)
		{
			cout << "Player " << i + 1 << ", please choose a Monster (0,1,2,3,4,5) ";
			monsterChoice = -1;
			while (!(cin >> monsterChoice))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please choose a Monster (0,1,2,3,4,5): ";
			}
			validChoice = find(chosenMonster, chosenMonster+6, monsterChoice);
			if (monsterChoice != -1)
			{
				if ((validChoice != chosenMonster + 6))
				{
					chosenMonster[monsterChoice] = -1;
					cout << "Player " << i + 1 << " has chosen monster " << monsterChoice << endl;
				}
				else
				{
					monsterChoice = -1;
				}
			}
		}
		
		Player * newPlayer = new Player(&monsterList[monsterChoice]);
		playerList.push_back(newPlayer);
		monsterChoice = -1;
	}

	cout << "Creating deck of cards....." << endl;
	Deck<GameCard*>* deckOfCards = initDeck();

	cout << "Game Ready!" << endl;

	return 0;
}