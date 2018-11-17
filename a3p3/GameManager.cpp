#include "GameManager.h"
#include "Card.h"
#include "DiscardCard.h"
#include "KeepCard.h"
#include "GameMapLoader.h"
#include "PieceManager.h"
#include "Util.h"

void GameManager::update() {
	cout << endl << this->currentPlayer->getMonster();

	if (this->currentPlayer->isRolling()) {
		cout << " is rolling : " << endl;
		const DiceRoll* lastRoll = this->currentPlayer->getLastRoll();
		cout << *lastRoll << endl;
	}
	else if (this->currentPlayer->isRelsoving()) {
		cout << " is resolving : " << endl;
		unordered_map<Die::Face, int> order = this->currentPlayer->getLastResolved();
		unordered_map<Die::Face, int>::iterator iter;
		cout << "[";
		for (iter = order.begin(); iter != order.end(); iter++) {
			cout << iter->first << " = " << iter->second << ",";
		}
		cout << "]" << endl;
	}
	else if (this->currentPlayer->isMoving()) {
		cout << " is moving : " << endl;
		cout << "Moved to " << this->currentPlayer->getCurrentZone() << endl;
	}
	else if (this->currentPlayer->isBuying()) {
		cout << " is buying: " << endl;
		cout << "Current Hand" << endl;
		for (auto card : this->currentPlayer->getHand()) {
			cout << card << endl;
		}
		cout << endl;
	}
	else {
		cout << " is Idle" << endl;
	}
}

void GameManager::executeStart(GameMap& map, vector<Player*>& playerList, Deck<GameCard*>& deckOfCards) {
	cout << "To begin, a map file must be loaded from your \"Map Directory\" " << endl;
	bool invalidMap = true;
	string mapName;

	//while loop to choose map to be loaded
	while (invalidMap)
	{
		cout << "Please enter a map file: ";
		cin >> mapName;
		mapName = "..\\king-of-new-york\\MapDirectory\\" + mapName;
		cout << "Your given map was: " << mapName << endl;
		map = *GameMapLoader::loadMap(mapName);
		if (!map.getList().empty())
		{
			if (map.duplicateFree() && map.allConnected())
			{
				cout << "Valid map loaded to play!" << endl;
				map.listAllZones();

				for (int i = 0; i < map.getList().size(); i++)
				{
					map.getList().at(i)->printNeighbours();
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
	MonsterCard* monsterList = initMonsterCards();
	cout << "Monster card options are the following:" << endl;
	int monsterChoice = -1;
	int chosenMonster[] = { 0,1,2,3,4,5 };
	int * validChoice;
	//printArray<MonsterCard>(monsterList, 6);

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
			validChoice = find(chosenMonster, chosenMonster + 6, monsterChoice);
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

		Player * newPlayer = new Player(&monsterList[monsterChoice], NULL);
		playerList.push_back(newPlayer);
		monsterChoice = -1;
	}

	cout << "Creating deck of cards....." << endl;
	deckOfCards = *initDeck();

	cout << "Game Ready!" << endl;
}

int* GameManager::executeStartupPhase(GameMap* map, vector<Player*>* playerList) {
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
	int * turnOrder = new int[playerList->size()];
	cout << "Player with the most attack faces: " << indOfMostAttack + 1 << endl;
	turnOrder[0] = indOfMostAttack;
	indOfMostAttack++;
	//cout << turnOrder[0] << " " << endl;
	for (int i = 1; i < playerList->size(); i++)
	{
		if (indOfMostAttack + 1 > playerList->size())
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
	for (int i = 0; i < playerList->size(); i++)
	{
		cout << "Player " << turnOrder[i] + 1 << " is " << i + 1 << "(st/nd/rd/th)" << endl;
	}

	cout << "Now players will choose which boroughs they'd like to begin in" << endl;

	bool undecidedStart;
	string chosenZone;
	for (int i = 0; i < playerList->size(); i++)
	{
		undecidedStart = true;
		while (undecidedStart)
		{
			cout << "Player " << turnOrder[i] + 1 << ", please choose your starting zone" << endl;
			getline(cin, chosenZone);

			if (map->zoneExists(chosenZone))
			{
				if (map->getZoneByName(chosenZone)->isNotFull() && map->getZoneByName(chosenZone)->setPlayerStart(playerList->at(turnOrder[i])))
				{
					undecidedStart = false;
				}
				else if (!map->getZoneByName(chosenZone)->isNotFull())
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
	cout << "Tiles have been placed..." << endl;
	cout << "Game Ready!" << endl;
	return turnOrder;
}