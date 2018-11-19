#ifndef MODERATE_DICE_RESOLVING_STRATEGY_H
#define MODERATE_DICE_RESOLVING_STRATEGY_H
#include "DiceResolvingStrategy.h"
/**
 * @brief A concrete DiceResolvingStrategy that a scripted player calls when he is executing its dice rolling phase. Player aims at resolving Energy(Die::Face::E), Heal(Die::Face::H) and Celebrity(Die::Face::C) first.
 */
class ModerateDiceResolvingStrategy:public DiceResolvingStrategy {
public:
	/**
	 * Executes the specific implemented DiceRollingStrategy. Resolves Energy(Die::Face::E), Heal(Die::Face::H) and Celebrity(Die::Face::C) first.
	 * @param player reference to the player which is rolling
	 */
	void execute(Player &player);
};
#endif
