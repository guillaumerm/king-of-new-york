#ifndef PHASE_VIEW_H
#define PHASE_VIEW_H
#include "Player.h"
#include "PhaseObserver.h"
#include "PhaseObserverInterface.h"

class PhaseView : public PhaseObserver, PhaseObserverInterface {
public:
	void update();
	void show();
	void setCurrentPlayer(Player *player);
private:
	Player* currentPlayer;
};
#endif