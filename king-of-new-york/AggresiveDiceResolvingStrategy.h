#ifndef AGGRESIVE_DICE_RESOLVING_STRATEGY_H
#define AGGRESIVE_DICE_RESOLVING_STRATEGY_H
#include "DiceResolvingStrategy.h"
#include "Player.h"
/**
 * @brief A concrete DiceResolvingStrategy that a scripted player calls when he is executing its dice rolling phase. Aims at playing Destruction(Die::Face::D) and Attack(Die::Face::A) first.
 */
class AggresiveDiceResolvingStrategy : public DiceResolvingStrategy {
public:
	/**
	 * Executes the specific implemented DiceRollingStrategy. Aims at playing Destruction(Die::Face::D) and Attack(Die::Face::A) first.
	 * @param player reference to the player which is rolling
	 */
	void execute(Player &player);
};
#endif
