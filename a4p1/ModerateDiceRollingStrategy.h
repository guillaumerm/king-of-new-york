#ifndef MODERATE_DICE_ROLLING_STRATEGY_H
#define MODERATE_DICE_ROLLING_STRATEGY_H
#include "DiceRollingStrategy.h"
/**
 * @brief A concrete DiceRollingStrategy that a scripted player calls when he is executing its dice rolling phase. Player aims at rolling Aims at rolling Energy(Die::Face::E), Heal(Die::Face::H) and Celebrity(Die::Face::C).
 */
class ModerateDiceRollingStrategy: public DiceRollingStrategy {
public:
	/**
	 * Executes the specific defined DiceRollingStrategy where the player aims at rolling Aims at rolling Energy(Die::Face::E), Heal(Die::Face::H) and Celebrity(Die::Face::C).
	 * @param player reference to the player which is rolling
	 * @param numberOfDice number of dice which the player is rolling
	 */
	void execute(Player &player, int numberOfDice);
};
#endif
