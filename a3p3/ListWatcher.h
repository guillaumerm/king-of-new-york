#ifndef LIST_WATCHER_H
#define LIST_WATCHER_H
#include "Player.h";
#include "Observer.h"
#include "GameMapNode.h"

using namespace std;

class ListWatcher : public Observer {
public:
	
	void update();
	
	GameMapNode * currentZone;
};
#endif
