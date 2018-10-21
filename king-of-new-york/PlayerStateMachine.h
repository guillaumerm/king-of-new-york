#pragma once
#include <exception>

using namespace std;

class PlayerStateMachine {
public:
	static enum PlayerState {
		Rolling,
		Resolving,
		Moving,
		Buying,
		Idle
	};
	static const int MAX_NUMBER_OF_ROLLS;
	PlayerStateMachine();
	bool isRolling() const;
	bool isMoving() const;
	bool isBuying() const;
	bool isResolving() const;
	bool isDone() const;
	void next();
	void initTurn();
	void endTurn();
	PlayerState getCurrentState() const;
private:
	int numberRolls;
	PlayerState currentState;
	PlayerState nextState;
};