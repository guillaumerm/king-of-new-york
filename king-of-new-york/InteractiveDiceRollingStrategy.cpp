#include "InteractiveDiceRollingStrategy.h"

void InteractiveDiceRollingStrategy::execute(Player & player, int numberOfDice) {
	bool *diceToKeep = new bool[numberOfDice];
	const DiceRoll *diceRoll = player.rollDice(numberOfDice);

	// While the player can roll/rerall continue this loop
	while (player.isRolling()) {
		cout << "You've rolled:" << *diceRoll << endl;

		// Asks if the player wants to reroll
		if (askYesNoQuestion("Do you want to reroll?", 'y', 'n')) {
			bool *diceToKeep = new bool[numberOfDice];

			// Dicide which dice to keep and which to roll.
			for (int i = 0; i < numberOfDice; i++) {
				diceToKeep[i] = askYesNoQuestion("Keep dice " + to_string(i + 1) + " which as symbol " + dieFaceToString(diceRoll->getFaceAt(i)), 'y', 'n');
			}

			diceRoll = player.rollDice(diceToKeep);
		}
		else {
			// End the rolling phase
			player.endPhase();
		}
	}
}
