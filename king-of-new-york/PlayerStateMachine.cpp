#include "PlayerStateMachine.h"

const int PlayerStateMachine::MAX_NUMBER_OF_ROLLS = 3;

PlayerStateMachine::PlayerStateMachine(): currentState(PlayerState::Rolling), nextState(PlayerState::Resolving) {}

void PlayerStateMachine::next() {
	switch (this->currentState) {
	case PlayerState::Rolling:
		if (this->numberRolls < PlayerStateMachine::MAX_NUMBER_OF_ROLLS) {
			this->nextState = PlayerState::Rolling;
			this->numberRolls++;
		}
		else {
			this->nextState = PlayerState::Resolving;
		}
		break;
	case PlayerState::Resolving:
		this->nextState = PlayerState::Moving;
		break;
	case PlayerState::Moving:
		this->nextState = PlayerState::Buying;
		break;
	case PlayerState::Buying:
		this->nextState = PlayerState::Idle;
		break;
	case PlayerState::Idle:
		this->nextState = PlayerState::Idle;
		break;
	}
}

void PlayerStateMachine::initTurn() {
	this->nextState = PlayerState::Rolling;
}

void PlayerStateMachine::endTurn() {
	if (this->isRolling() || this->isResolving()) {
		throw exception("Player must roll and resolve before ending its turn.");
	}
}

bool PlayerStateMachine::isBuying() const {
	return this->currentState == PlayerState::Buying;
}

bool PlayerStateMachine::isDone() const {
	return this->currentState == PlayerState::Idle;
}

bool PlayerStateMachine::isMoving() const {
	return this->currentState == PlayerState::Moving;
}

bool PlayerStateMachine::isResolving() const {
	return this->currentState == PlayerState::Resolving;
}

bool PlayerStateMachine::isRolling() const {
	return this->currentState == PlayerState::Rolling;
}

PlayerStateMachine::PlayerState PlayerStateMachine::getCurrentState() const {
	return this->currentState;
}