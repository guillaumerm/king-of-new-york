#ifndef INTERACTIVE_DICE_ROLLING_STRATEGY_H
#define INTERACTIVE_DICE_ROLLING_STRATEGY_H
#include "DiceRollingStrategy.h"
/**
 * @brief A concrete DiceRollingStrategy that a player calls when he is executing its dice rolling phase. Player interactively decides which dice to keep or reroll.
 */
class InteractiveDiceRollingStrategy :public DiceRollingStrategy {
public:
	/**
	 * Executes the specific defined DiceRollingStrategy where the player interactively decides which dice to keep or reroll.
	 * @param player reference to the player which is rolling
	 * @param numberOfDice number of dice which the player is rolling
	 */
	void execute(Player &player, int numberOfDice);
};
#endif
