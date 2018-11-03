#include "GameManager.h"
#include "Card.h"
#include "DiscardCard.h"
#include "KeepCard.h"

template <typename T> void printVector(vector<T> aVector) {
	typename vector<T>::iterator anIterator;
	for (anIterator = aVector.begin(); anIterator != aVector.end(); anIterator++) {
		cout << *anIterator << endl;
	}
}

template <typename T> void printSet(unordered_set<T*> aVector) {
	typename unordered_set<T*>::iterator anIterator;
	for (anIterator = aVector.begin(); anIterator != aVector.end(); anIterator++) {
		cout << **anIterator << endl;
	}
}

template <class T> void printArray(T* array, int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << endl;
	}
	cout << endl;
}

/**
 * Function used to aske a yes-no question.
 * @param question question being answered
 * @param positiveAnswer char representing a positive asnwer for the question
 * @param negativeAnswer char representing a negative answer for the question
 * @return true if answer with positiveAnswer, false if answered with a negativeAnswer
 */
bool askYesNoQuestion(string question, char positiveAnswer, char negativeAnswer) {
	char answer = -1;
	while (answer != positiveAnswer && answer != negativeAnswer) {
		cout << question << "(" << positiveAnswer << " or " << negativeAnswer << "):";
		cin >> answer;
	}
	return answer == positiveAnswer;
}

/**
 * Function used to asked a choice question.
 * @param question the question being asked
 * @param lowerChoice lower bound limit for choices

 */
int askChoiceQuestion(string question, int lowerChoice, int upperChoice) {
	int choice = -1;
	while (choice < lowerChoice || choice > upperChoice) {
		cout << question;
		cin >> choice;
	}
	return choice;
}

//From A2 Part1
void executeStart(GameMap newMap, vector<Player*> playerList, Deck<GameCard*>* deckOfCards) {
	cout << "To begin, a map file must be loaded from your \"Map Directory\" " << endl;
	bool invalidMap = true;
	string mapName;
	newMap = GameMap::GameMap();

	//while loop to choose map to be loaded
	while (invalidMap)
	{
		cout << "Please enter a map file: ";
		cin >> mapName;
		mapName = "MapDirectory\\" + mapName; //Edited for testing purposes
		cout << "Your given map was: " << mapName << endl;
		newMap = *GameMapLoader::loadMap(mapName);
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

	MonsterCard* monsterList = initMonsterCards();
	cout << "Monster card options are the following:" << endl;
	int monsterChoice = -1;
	int chosenMonster[] = { 0,1,2,3,4,5 };
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

		Player * newPlayer = new Player(&monsterList[monsterChoice]);
		playerList.push_back(newPlayer);
		monsterChoice = -1;
	}

	cout << "Creating deck of cards....." << endl;
	deckOfCards = initDeck();

}

//From A2 Part 2
void executeStartupPhase(GameMap map, int noStart, vector<Player*> playerList, vector<Tile*> tileStack) {

	//Restricting some zones from being where the players can start the game at
	for (int i = 0; i < noStart; i++)
	{
		map.getList().at(i)->noStartHere(); //Problematic line of code
	}

	playerList;
	
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
	int * turnOrder = new int[playerList.size()];
	cout << "Player with the most attack faces: " << indOfMostAttack + 1 << endl;
	turnOrder[0] = indOfMostAttack;
	indOfMostAttack++;
	//cout << turnOrder[0] << " " << endl;
	for (int i = 1; i < playerList.size(); i++)
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

	initTokens(13, 13, 5, 15);
	//Assumes that first 3 zones in map list have 1 stack of 3 tiles each
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
	
}

void executeBuyCardsPhase(Player &player, vector<GameCard> cardsAvailable) {
	unordered_set<GameCard*> cardsToBeBought;
	int cardPosition = -1;
	while (cardsToBeBought.size() < cardsAvailable.size() && cardPosition != 0) {
		cardPosition = askChoiceQuestion("Enter the position of the card that you want to buy: (0)to buy the cards", 0, cardsAvailable.size() - 1);
		if (cardPosition != 0 && !cardsToBeBought.emplace(&cardsAvailable.at(cardPosition - 1)).second) {
			cout << "This card is already in your basket" << endl;
		}
	}

	cout << "Content of your basket" << endl;
	printSet(cardsToBeBought);
	GameCard *cards = new GameCard[cardsToBeBought.size()];
	unordered_set<GameCard*>::iterator cardIter;
	int index = 0;
	for (cardIter = cardsToBeBought.begin(); cardIter != cardsToBeBought.end(); cardIter++) {
		cards[index++] = **cardIter;
	}
	player.buyCards(cards, cardsToBeBought.size());
}

void dealNewCardsToBuy(Player &player, vector<GameCard> cardsAvailable) {
	do {
		player.removeEnergyCubes(2);
		cout << "Player has " << player.getEnergyCubes() << " Energy Cubes" << endl;
		cardsAvailable.clear();
		cardsAvailable.push_back(DiscardCard("New Card 1", "Description", 1));
		cardsAvailable.push_back(KeepCard("New Card 2", "Description", 2));
		cardsAvailable.push_back(DiscardCard("New Card 3", "Description", 3));
		printVector<GameCard>(cardsAvailable);
	} while (askYesNoQuestion("Do you want to deal new cards? (This will cost two energy cubes)", 'y', 'n') && player.getEnergyCubes() > 1);
}


void executeRollDicePhase(Player &player, int numberOfDice) {
	cout << "Game manager is executing roll phase!" << endl;
	bool *diceToKeep = new bool[numberOfDice];
	const DiceRoll *diceRoll = player.rollDice(numberOfDice);
	//cout << "A dice roll has been determined" << endl;
	// While the player can roll/rerall continue this loop
	while (player.isRolling()) {
		cout << "You've rolled:" << *diceRoll << endl;

		// Asks if the player wants to reroll
		if (askYesNoQuestion("Do you want to reroll?", 'y', 'n')) {
			bool *diceToKeep = new bool[numberOfDice];

			// Dicide which dice to keep and which to roll.
			for (int i = 0; i < numberOfDice; i++) {
				diceToKeep[i] = askYesNoQuestion("Keep dice " + to_string(i + 1) + " which as symbol " + dieFaceToString(diceRoll->getFaceAt(i)), 'y', 'n');
			}

			diceRoll = player.rollDice(diceToKeep);
		}
		else {
			// End the rolling phase
			player.endPhase();
		}
	}
}


void executeResolveDicePhase(Player &player) {
	// Decide the order in which the dice will be played.
	unordered_set<Die::Face> order;
	while (order.size() < 6) {
		int choice = askChoiceQuestion("Enter the symbol of the dice you want to resolve [A(0), C(1), D(2), E(3), H(4), O(5)]:", 0, 5);

		if (!order.emplace((Die::Face)choice).second) {
			cerr << "You have already decided for this symbol." << endl;
		}
	}
	// Given the order obtain the count for each Die::Face from the last roll of the player
	unordered_map<Die::Face, int> resolveDecision = player.resolveDice(order);
	unordered_map<Die::Face, int>::iterator iter;

	cout << "The order you decided to resolve the dice is the following" << endl;

	for (iter = resolveDecision.begin(); iter != resolveDecision.end(); iter++) {
		cout << iter->first << " => " << iter->second << endl;
	}
}

void executeMovePhase(Player *player, GameMap *map) {
	//PLAYER.GETCURRENTZONE returns a string may want to set it to return a GAMEMAPNODE
	vector<GameMapNode*> neighbours = map->getZoneByName(player->getCurrentZone())->getNeighbours();
	//appear to be setting everyone to uppermanhatten
	if (neighbours.size() == 0) {
		cout << "Since you are in Upper Manhatten you need to stay there." << endl;
		player->endPhase();
	}
	else if (neighbours.size() == 1) {
		cout << "Since you were in " << player->getCurrentZone() << " you were moved to " << neighbours.at(0)->getZoneName() << endl;
		player->move(map, neighbours.at(0)->getZoneName());
	}
	else {
		cout << "List of possible zones:" << endl;
		for (int i = 0; i < neighbours.size(); i++) {
			cout << (i + 1) << ")" << neighbours.at(i)->getZoneName() << endl;
		}
		int choice = askChoiceQuestion("Select which zone you want to move to? (0 to skip this phase)", 0, neighbours.size());
		if (choice != 0) {
			player->move(map, neighbours.at(choice - 1)->getZoneName());
		}
		else {
			player->endPhase();
		}
	}
}