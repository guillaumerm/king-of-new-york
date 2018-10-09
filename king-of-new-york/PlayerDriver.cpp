#include "Player.h"
#include "MonsterCard.h"
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
	system("pause");
	return 0;
}