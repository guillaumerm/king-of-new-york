#include "GameManager.h"

const int GameManager::NUMBER_OF_CARDS = 64;
using namespace std;
GameManager::GameManager()
{
	this->statisticView = new GameStatisticView();
	this->cardPlayedView = new CardPlayedView();
	this->phaseView = new PhaseView();
	this->diceView = new DiceView();
	this->playerList = new vector<Player*>();
	this->deckOfCards = new Deck<GameCard*>(NUMBER_OF_CARDS);
	this->cardsAvailable = new vector<GameCard*>();
	this->executeStart();
	this->executeStartupPhase();
}

GameManager::~GameManager()
{
	delete this->cardsAvailable;
	delete this->phaseView;
	delete this->statisticView;
	delete this->deckOfCards;
	delete this->map;
}

void GameManager::executeStart() {
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
		this->map = GameMapLoader::loadMap(mapName);
		if (!this->map->getList().empty())
		{
			if (this->map->duplicateFree() && this->map->allConnected())
			{
				cout << "Valid map loaded to play!" << endl;
				this->map->listAllZones();

				for (int i = 0; i < this->map->getList().size(); i++)
				{
					this->map->getList().at(i)->printNeighbours();
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
	PlayerStrategyDirector *director = new PlayerStrategyDirector();
	PlayerStrategyBuilder* moderateBuilder = new ModeratePlayerStrategyBuilder();
	PlayerStrategyBuilder* aggresiveBuilder = new AggresivePlayerStrategyBuilder();
	PlayerStrategyBuilder* interactiveBuilder = new InteractivePlayerStrategyBuilder();

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
		
		int playerType = askChoiceQuestion("Will the player be a (1) Moderate NPC (2) Aggresive NPC (3) Human Player?", 1, 3);

		if (playerType == 1) {
			director->setPlayerStrategyBuilder(moderateBuilder);
		}
		else if (playerType == 2) {
			director->setPlayerStrategyBuilder(aggresiveBuilder);
		}
		else {
			director->setPlayerStrategyBuilder(interactiveBuilder);
		}
		
		director->constructPlayerStrategy();

		Player * newPlayer = new Player(&monsterList[monsterChoice], director->getPlayerStrategy());
		dynamic_cast<AttackSubject*>(newPlayer)->attach(this);
		dynamic_cast<GameStatisticSubject*>(newPlayer)->attach(this->statisticView);
		dynamic_cast<PhaseSubject*>(newPlayer)->attach(this->phaseView);
		dynamic_cast<DiceSubject*>(newPlayer->getRollFacility())->attach(this->diceView);
		this->playerList->push_back(newPlayer);
		monsterChoice = -1;
	}

	delete director;
	delete interactiveBuilder;
	delete moderateBuilder;
	delete aggresiveBuilder;

	cout << "Creating deck of cards....." << endl;
	this->deckOfCards = initDeck(this->cardPlayedView);

	cout << "Game Ready!" << endl;
}

void GameManager::executeStartupPhase() {
	cout << "To decide the turn order, all players will roll the dice and the one with most Attack shall go first" << endl;
	int mostAttack = -1;
	int currentAttack = -1;
	int indOfMostAttack = -1;
	for (int i = 0; i < playerList->size(); i++)
	{
		this->diceView->setCurrentFacility(playerList->at(i)->getRollFacility());
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
	this->turnOrder = new int[this->playerList->size()]();
	cout << "Player with the most attack faces: " << indOfMostAttack + 1 << endl;
	this->turnOrder[0] = indOfMostAttack;
	indOfMostAttack++;
	//cout << turnOrder[0] << " " << endl;
	for (int i = 1; i < this->playerList->size(); i++)
	{
		if (indOfMostAttack + 1 > this->playerList->size())
		{
			indOfMostAttack -= this->playerList->size();
			this->turnOrder[i] = indOfMostAttack;
		}
		this->turnOrder[i] = indOfMostAttack;
		indOfMostAttack++;
		//cout << turnOrder[i] << " " << endl;
	}
	//NOTE: For simplicity "clockwise order" will be assumed to be in the order players were created
	cout << "Therefore the turn order is:" << endl;
	for (int i = 0; i < this->playerList->size(); i++)
	{
		cout << "Player " << this->turnOrder[i] + 1 << " is " << i + 1 << "(st/nd/rd/th)" << endl;
	}

	map->getZoneByName("Lower Manhatten")->addPlayer(playerList->at(turnOrder[0]));
	playerList->at(turnOrder[0])->setCurrentZone("Lower Manhatten");

	cout << "Now players will choose which boroughs they'd like to begin in" << endl;

	bool undecidedStart;
	string chosenZone;
	for (int i = 1; i < this->playerList->size(); i++)
	{
		undecidedStart = true;
		while (undecidedStart)
		{
			cout << "Player " << this->turnOrder[i] + 1 << ", please choose your starting zone" << endl;
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

	try {
		this->cardsAvailable->push_back(*this->deckOfCards->deal());
		this->cardsAvailable->push_back(*this->deckOfCards->deal());
		this->cardsAvailable->push_back(*this->deckOfCards->deal());
	}
	catch (...) {
		exit(1);
	}


	cout << "Game Ready!" << endl;
}

Player *GameManager::hasWon() {
	vector<Player *>::iterator curPlayer;
	int dead = 0;
	Player * lastALife = NULL;
	for (curPlayer = this->playerList->begin(); curPlayer != this->playerList->end(); curPlayer++) {
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

	if (dead == this->playerList->size() - 1) {
		return lastALife;
	}

	return NULL;
}

void GameManager::update(string playerName, bool attackManhatten, int attackAmount) {
	for (auto player : *this->playerList) {
		if (player->getMonster() != playerName && attackManhatten == player->isInManhatten() && !player->isDead()) {
			player->removeLifePoints(attackAmount);
			if (attackManhatten) {
				for (auto zone : this->map->getList()) {
					if (zone->isNotFull() && zone->getZoneName() != "Lower Manhatten" && zone->getZoneName() != "Midtown" && zone->getZoneName() != "Upper Manhatten") {
						map->movePlayer(player, player->getCurrentZone(), zone->getZoneName());
						player->setCurrentZone(zone->getZoneName());
						return;
					}
				}
			}
		}
	}
}

void GameManager::play()
{
	int round = 1;
	std::cout << flush;
	std::system("CLS");
	Player* winningPlayer;
	// Main game loop - play until someone wins
	while (!(winningPlayer = this->hasWon())) {
		std::cout << " ----------- Round " << to_string(round) << " ----------- " << endl << endl;

		GameMapNode *zone = this->map->getZoneByName("Lower Manhatten");
		if (zone->getPlayersCount() > 0) {
			for (auto player : zone->getPlayers()) {
				player->addEnergyCubes(1);
				player->addVictoryPoints(1);
			}
		}

		zone = this->map->getZoneByName("Midtown");
		if (zone->getPlayersCount() > 0) {
			for (auto player : zone->getPlayers()) {
				player->addEnergyCubes(1);
				player->addVictoryPoints(2);
			}
		}

		zone = this->map->getZoneByName("Upper Manhatten");
		if (zone->getPlayersCount() > 0) {
			for (auto player : this->map->getZoneByName("Upper Manhatten")->getPlayers()) {
				player->addEnergyCubes(2);
				player->addVictoryPoints(2);
			}
		}

		// Display Stats after each turn
		this->statisticView->show();

		for (int turn = 0; turn < playerList->size() && !(winningPlayer = this->hasWon()); turn++) {
			Player* curPlayer = playerList->at(turnOrder[turn]);

			this->phaseView->setCurrentPlayer(curPlayer);
			this->diceView->setCurrentFacility(curPlayer->getRollFacility());

			// Precondition of playing a turn the player must not be dead
			if (curPlayer->isDead()) {
				continue;
			}
			curPlayer->startTurn();
			curPlayer->executeTurn(map, this->cardsAvailable, 6, this->deckOfCards);
			curPlayer->endTurn();
			this->cardPlayedView->show();
			this->cardPlayedView->clear();
			// Display Stats after each turn
			this->statisticView->show();
		}
		round++;
		//std::cout << flush;
		//std::system("CLS");
	}

	std::cout << endl << "Game has ended!" << endl;
	
	std::cout << winningPlayer->getMonster() << " has won!" << endl;
	this->statisticView->show();
	system("Pause");
}
