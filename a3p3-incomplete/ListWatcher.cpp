#include "ListWatcher.h"

using namespace std;

void ListWatcher::update()
{
	cout << endl << "Current Game Statistics:" << endl;
	cout << this->currentZone << endl;
	
	if (currentZone->getPlayersCount() > 0)
	{
		cout << "IF ENTERED!!!!!!!!" << endl;
		for (int i = 0; i < currentZone->getPlayers().size(); i++)
		{
			cout << "For ENTERED!!!!!!!!" << endl;
			Player * currentPlayer = currentZone->getPlayers().at(i);
			cout << "PLAYER OBTAined" << endl;
			cout << currentPlayer->getMonster() << " currently has " << currentPlayer->getVictoryPoints() << " Victory Points, and has " <<
				currentPlayer->getLifePoints() << " Hit Points" << endl;
			cout << currentPlayer->getMonster() << " is located at " << currentZone << endl;
		}
	}
}