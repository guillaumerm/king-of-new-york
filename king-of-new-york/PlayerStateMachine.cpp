#include "PlayerStateMachine.h"

const int PlayerStateMachine::MAX_NUMBER_OF_ROLLS = 3;

PlayerStateMachine::PlayerStateMachine(): currentState(PlayerState::Rolling), nextState(PlayerState::Resolving) {}

void PlayerStateMachine::proceed() {
 	this->currentState = this->nextState;
	switch (this->currentState) {
	case PlayerState::Rolling:
		this->numberRolls++;
		if (this->numberRolls + 1 >= PlayerStateMachine::MAX_NUMBER_OF_ROLLS) {
			this->nextState = PlayerState::Resolving;
		}
		else {
			this->nextState = PlayerState::Rolling;
		}
		break;
	case PlayerState::Resolving:
		if (this->resolved) {
			this->nextState = PlayerState::Moving;
			throw exception("Player has already resolved.");
			exit(1);
		}
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

void PlayerStateMachine::next() {
	switch (this->currentState) {
	case PlayerState::Rolling:
		if (this->numberRolls < 1) {
			this->nextState = PlayerState::Rolling;
			this->currentState = PlayerState::Rolling;
			throw exception("Rolling at least once is madantory");
		}
		this->currentState = PlayerState::Resolving;
		this->nextState = PlayerState::Moving;
		break;
	case PlayerState::Resolving:
		if (!this->resolved) {
			this->nextState = PlayerState::Moving;
			throw exception("Resolving is mandantory");
		}
		this->nextState = PlayerState::Moving;
		this->nextState = PlayerState::Buying;
		break;
	case PlayerState::Moving:
		this->nextState = PlayerState::Buying;
		this->nextState = PlayerState::Idle;
		break;
	case PlayerState::Buying:
		this->nextState = PlayerState::Idle;
		this->currentState = PlayerState::Idle;
		break;
	case PlayerState::Idle:
		this->nextState = PlayerState::Idle;
		this->currentState = PlayerState::Idle;
		break;
	}
}

void PlayerStateMachine::setCurrentState(PlayerState state) {
	this->currentState = state;
}

void PlayerStateMachine::initTurn() {
	this->numberRolls = 0;
	this->resolved = false;
	this->currentState = PlayerState::Rolling;
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

bool PlayerStateMachine::isIdle() const {
	return this->currentState == PlayerState::Idle;
}

PlayerStateMachine::PlayerState PlayerStateMachine::getCurrentState() const {
	return this->currentState;
}