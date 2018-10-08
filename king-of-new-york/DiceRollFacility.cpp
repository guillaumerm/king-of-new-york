#include "DiceRollingFacility.h"

DiceRollingFacility::DiceRollingFacility() {
	this->die = new Die();
}

const DiceRoll* DiceRollingFacility::getLastRoll() const {
	return this->diceRolls.back();
}

const DiceRoll* DiceRollingFacility::resolve(bool resolution[]) {
	const DiceRoll *diceRoll = this->diceRolls.back();

	// Resolve the dice dicided to be kept.
	Die::Face* roll = new Die::Face[diceRoll->getNumberDice()];
	int rollIndex = 0;
	for (int i = 0; i < diceRoll->getNumberDice; i++) {
		if (resolution[i]) {
			roll[rollIndex++] = diceRoll->getFaceAt(i);
		}
	}

	// Roll the remaining die that were rejected (if any is rejected)
	if (!((rollIndex + 1) - diceRoll->getNumberDice)) {
		generateRoll(&roll[rollIndex], (rollIndex + 1) - diceRoll->getNumberDice);
	}

	const DiceRoll *resolvedDiceRoll = new DiceRoll(roll, diceRoll->getNumberDice());

	this->roll.push(resolvedDiceRoll);

	return resolvedDiceRoll;
}

void DiceRollingFacility::generateRoll(Die::Face* roll, int numberDice) const {
	for (int i = 0; i < numberDice; i++) {
		roll[i] = this->die->roll();
	}
}

const DiceRoll* DiceRollingFacility::roll(int numberDice) {
	// Roll the die the desired number of times
	Die::Face* roll = new Die::Face[numberDice];

	const DiceRoll* diceRoll = new DiceRoll(generateRoll(roll, numberDice), numberDice);

	this->diceRolls.push_back(diceRoll);

	return diceRoll;
}