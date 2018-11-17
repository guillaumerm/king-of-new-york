#include "PhaseView.h"

void PhaseView::update()
{
	this->show();
}

void PhaseView::show() {
	std::cout << this->currentPlayer->getMonster();

	if (this->currentPlayer->isRolling()) {
		cout << " is rolling : " << endl;
		const DiceRoll* lastRoll = this->currentPlayer->getLastRoll();
		cout << *lastRoll << endl;
	}
	else if (this->currentPlayer->isRelsoving()) {
		cout << " is resolving : " << endl;
 		unordered_map<Die::Face, int> order = this->currentPlayer->getLastResolved();
		cout << "[";
		for (auto iter : order) {
			cout << iter.first << " = " << iter.second << ",";
		}
		cout << "]" << endl;
	}
	else if (this->currentPlayer->isMoving()) {
		cout << " is moving : " << endl;
		cout << "Moved to " << this->currentPlayer->getCurrentZone() << endl;
	}
	else if (this->currentPlayer->isBuying()) {
		cout << " is buying: " << endl;
		cout << "Current Hand" << endl;
		for (auto card : this->currentPlayer->getHand()) {
			cout << card << endl;
		}
		cout << endl;
	}
	else {
		cout << "Idle" << endl;
	}
}

void PhaseView::setCurrentPlayer(Player * player)
{
	this->currentPlayer = player;
}
