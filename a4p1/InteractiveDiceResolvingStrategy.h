#ifndef INTERACTIVE_DICE_RESOLVING_STRATEGY_H
#define INTERACTIVE_DICE_RESOLVING_STRATEGY_H
#include "DiceResolvingStrategy.h"
/**
 * @brief A concrete DiceResolvingStrategy that a player calls from which he interactively decides the resolve order of his last DiceRoll.
 */
class InteractiveDiceResolvingStrategy : public DiceResolvingStrategy {
public:
	/**
	 * Executes the specific implemented DiceRollingStrategy. The Player interactively decide the resolve order of his last DiceRoll.
	 * @param player reference to the player which is rolling
	 */
	void execute(Player &player);
};
#endif
