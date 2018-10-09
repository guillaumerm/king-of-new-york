#include "Player.h"
#include "MonsterCard.h"
#include "GameCard.h"
#include "KeepCard.h"
#include "DiscardCard.h"


#include <iostream>
#include <time.h>

using namespace std;

int main() {
	/* initialize random seed: */
	/* Can be commented for testing purposes*/
	srand(time(NULL));

	MonsterCard *monsterCard = new MonsterCard("Sherif", "A TRex sherif");
	Player *player = new Player(monsterCard, 30);
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
	
	system("pause");
	return 0;
}