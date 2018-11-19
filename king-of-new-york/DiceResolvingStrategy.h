#ifndef DICE_RESOLVING_STRATEGY_H
#define DICE_RESOLVING_STRATEGY_H
#include "Player.h"

using namespace std;

class Player;
/**
 * @brief An interface that declare what a DiceResolvingStrategy requires to implement. A DiceResolvingStrategy is the strategy that a Player calls when he is executing its dice resolving phase.
 */
class DiceResolvingStrategy {
public:

	/**
	 * Executes the specific defined DiceResolvingStrategy
	 * @param player reference to the player which is rolling
	 */
	virtual void execute(Player &player) = 0;
};
#endif
