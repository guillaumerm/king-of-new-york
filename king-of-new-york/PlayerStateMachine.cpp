#include "PlayerStateMachine.h"

const int PlayerStateMachine::MAX_NUMBER_OF_ROLLS = 3;

PlayerStateMachine::PlayerStateMachine(): currentState(PlayerState::Rolling), nextState(PlayerState::Resolving) {}

void PlayerStateMachine::proceed() {
	switch (this->currentState) {
	case PlayerState::Rolling:
		if (this->numberRolls + 1 > 3) {
			throw exception("Player has rolled 3 times already.");
			exit(1);
		}
		this->numberRolls++;
		this->nextState = Resolving;
		break;
	case PlayerState::Resolving:
		if (this->resolved) {
			this->nextState = PlayerState::Moving;
			throw exception("Player has already resolved.");
			exit(1);
		}
		this->resolved = true;
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
	if (this->currentState == Rolling && this->numberRolls <= 0) {
		return;
	}
	else if (this->currentState == Resolving && !this->resolved) {
		return;
	}
	this->currentState = this->nextState;
	this->nextState = static_cast<PlayerState>(((int)this->nextState + 1) % (PlayerState::Idle+1));
}

void PlayerStateMachine::setCurrentState(PlayerState state) {
	this->currentState = state;
}

void PlayerStateMachine::initTurn() {
	this->numberRolls = 0;
	this->resolved = false;
	this->currentState = PlayerState::Rolling;
	this->nextState = PlayerState::Resolving;
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