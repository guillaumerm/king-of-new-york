#include "Player.h"
#include "MonsterCard.h"
#include "GameCard.h"
#include "KeepCard.h"
#include "DiscardCard.h"
#include "GameMapNode.h"
#include "GameMap.h"
#include "GameMapLoader.h"

#include <iostream>
#include <time.h>

using namespace std;

int main000() {
	MonsterCard *monsterCard = new MonsterCard("Sherif", "A TRex sherif");
	string startingZone = "Bronx";
	Player *player = new Player(monsterCard, 30, startingZone);
	cout << *player->rollDice(6) << endl;
	bool resolution[6] = { true, false, true, false, false, false };
	cout << *player->resolveDice(resolution) << endl;
	GameCard cards[] = { KeepCard("KeepCard 1", "KeepCard 1", 3), DiscardCard("DiscardCard 1", "DiscardCard 1", 3) , KeepCard("KeepCard 2", "KeepCard 2", 3) };
	
	try
	{
		player->buyCards(cards, 3);
	}
	catch (const out_of_range& exception)
	{
		cerr << exception.what() << endl;
		exit(1);
	}

	GameMap *map = GameMapLoader::loadMap("new_york.map");
	cout << "Player zone before moving:" << player->getCurrentZone() << endl;
	player->move(map, "Queens");
	cout << "Player zone after moving:" << player->getCurrentZone() << endl;
	system("pause");
	return 0;
}