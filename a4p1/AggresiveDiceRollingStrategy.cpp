#include "AggresiveDiceRollingStrategy.h"

void AggresiveDiceRollingStrategy::execute(Player &player, int numberOfDice) {
	bool *diceToKeep = new bool[numberOfDice];
	const DiceRoll *diceRoll = player.rollDice(numberOfDice);

	// While the player can roll/rerall continue this loop or the player as a full roll of attack and destruction
	while (player.isRolling() && !((diceRoll->getSumAttack() + diceRoll->getSumDesctruction()) < numberOfDice)) {

		// Player rerolls die that is not attack or destruction
		delete diceToKeep;
		diceToKeep = new bool[numberOfDice];
		for (int i = 0; i < numberOfDice; i++) {
			if (diceRoll->getFaceAt(i) != Die::Face::A || diceRoll->getFaceAt(i) != Die::Face::D) {
				diceToKeep[i] = false;
			}
			else {
				diceToKeep[i] = true;
			}
		}

		diceRoll = player.rollDice(diceToKeep);
	}

	if (player.isRolling()) {
		// End the rolling phase
		player.endPhase();
	}
}