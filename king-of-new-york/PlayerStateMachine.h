#pragma once
#include <exception>

using namespace std;

/**
 * @brief Class that takes care of keeping track of a players turn. Also include methods to help navigate through game conditions which requires the state of the player to bein a given state.
 */
class PlayerStateMachine {
public:
	/**
	 * Enum class gathering the different possible player states
	 */
	static enum PlayerState {
		Rolling, /**< Rolling state */
		Resolving, /**< Resolving state */
		Moving, /**< Moving state */
		Buying, /**< Buying state */
		Idle /**< Idle state */
	};

	/**
	 * Maximum number of rolls allowed per turns
	 */
	static const int MAX_NUMBER_OF_ROLLS;

	/**
	 * Parameterless constructor
	 */
	PlayerStateMachine();

	/**
	 * Check if the machine is in the Rolling PlayerState
	 * @return true if in PlayerState::Rolling, false otherwise
	 */
	bool isRolling() const;

	/**
	 * Check if the machine is in the Moving PlayerState
	 * @return true if in PlayerState::Moving, false otherwise
	 */
	bool isMoving() const;

	/**
	 * Check if the machine is in the Buying PlayerState
	 * @return true if in PlayerState::Buying, false otherwise
	 */
	bool isBuying() const;

	/**
	 * Check if the machine is in the Resolving PlayerState
	 * @return true if in PlayerState::Resolving, false otherwise
	 */
	bool isResolving() const;

	/**
	 * Proceed normally through the state machine
	 * @return true if in PlayerState::Resolving, false otherwise
	 */
	void proceed();

	bool isDone() const;

	/**
	 * Check if the machine is in the Rolling PlayerState
	 * @return true if in PlayerState::Rolling, false otherwise
	 */
	bool isIdle() const;

	/**
	 * Skips to the next state if possible. This method is useful to skip the optional moving/rolling states.
	 */
	void next();

	/**
	 * Sets the state machine current state to Rolling and reset the numberOfRolls and resolved conditions.
	 */
	void initTurn();

	/**
	 * Sets the state machine to the idle state.
	 */
	void endTurn();

	/**
	 * Get the current PlayerState of the machine.
	 * @param PlayerState that the machine is currently in
	 */
	PlayerState getCurrentState() const;

	/**
	 * Sets the current PlayerState to the state machine
	 * @param newState the new PlayerState
	 */
	void setCurrentState(PlayerState);
private:
	int numberRolls; /**< Number of rolls in a turn*/
	bool resolved; /**< If the player has resolved this turn*/
	PlayerState currentState; /**< Current PlayerState of the state machine */
	PlayerState nextState; /**< The next state of the state machine*/
};