#include "GameStatisticSubject.h"

GameStatisticSubject::GameStatisticSubject()
{
	this->observers = new std::list<GameStatisticObserver*>();
}

void GameStatisticSubject::attach(GameStatisticObserver * ob)
{
	this->observers->push_back(ob);
}

void GameStatisticSubject::detach(GameStatisticObserver * ob)
{
	this->observers->remove(ob);
}

void GameStatisticSubject::notify(std::string playerName, std::string location, int victoryPoint)
{
	for (auto observer : *this->observers) {
		observer->update(playerName, location, victoryPoint);
	}
}

GameStatisticSubject::~GameStatisticSubject()
{
	delete this->observers;
	this->observers = NULL;
}

