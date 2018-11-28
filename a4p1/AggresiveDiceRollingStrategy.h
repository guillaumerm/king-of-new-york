#ifndef AGGRESIVE_DICE_ROLL_STRATEGY_H
#define AGGRESIVE_DICE_ROLL_STRATEGY_H
#include "DiceRollingStrategy.h"
#include "Player.h"
/**
 * @brief A concrete DiceRollingStrategy that a scripted player calls when he is executing its dice rolling phase. Aims at rolling Destruction(Die::Face::D) and Attack(Die::Face::A).
 */
class AggresiveDiceRollingStrategy: public DiceRollingStrategy {
public:
	/**
	 * Executes the specific defined DiceRollingStrategy where the player aims at rolling Destruction(Die::Face::D) and Attack(Die::Face::A).
	 * @param player reference to the player which is rolling
	 * @param numberOfDice number of dice which the player is rolling
	 */
	void execute(Player &player, int numberOfDice);
};
#endif
