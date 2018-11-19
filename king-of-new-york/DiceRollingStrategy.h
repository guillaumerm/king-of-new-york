#ifndef DICE_ROLL_STRATEGY_H
#define DICE_ROLL_STRATEGY_H
#include "Player.h"

using namespace std;

class Player;
/**
 * @brief An interface that declare what a DiceRollingStrategy requires to implement. A DiceRollingStrategy is the strategy that a Player calls when he is executing its dice rolling phase.
 */
class DiceRollingStrategy {
public:

	/**
	 * Executes the specific defined DiceRollingStrategy
	 * @param player reference to the player which is rolling
	 * @param numberOfDice number of dice which the player is rolling
	 */
	virtual void execute(Player &player, int numberOfDice) = 0;
};
#endif