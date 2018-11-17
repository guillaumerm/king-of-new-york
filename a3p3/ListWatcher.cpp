#include "ListWatcher.h"

using namespace std;

void ListWatcher::update()
{	
	if (currentZone->getPlayersCount() > 0)
	{
		cout << endl << "Current Occupants of " << currentZone->getZoneName() << ":" << endl;
		for (int i = 0; i < currentZone->getPlayers().size(); i++)
		{
			Player * currentPlayer = currentZone->getPlayers().at(i);
			cout << currentPlayer->getMonster() << " currently has " << currentPlayer->getVictoryPoints() << " Victory Points, and has " <<
				currentPlayer->getLifePoints() << " Hit Points" << endl;
		}
	}
}