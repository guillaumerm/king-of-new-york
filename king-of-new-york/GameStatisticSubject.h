#ifndef GAME_STATISTIC_SUBJECT_H
#define GAME_STATISTIC_SUBJECT_H
#include <list>
#include <string>
#include "GameStatisticObserver.h"

class GameStatisticSubject {
public:
	GameStatisticSubject();
	void attach(GameStatisticObserver *ob);
	void detach(GameStatisticObserver *ob);
	void notify(std::string playerName, std::string location, int victoryPoint);
	~GameStatisticSubject();
private:
	std::list<GameStatisticObserver*> *observers;
};
#endif
