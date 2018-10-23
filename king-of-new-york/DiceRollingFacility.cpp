#include "DiceRollingFacility.h"
#include <time.h>

DiceRollingFacility::DiceRollingFacility() {
	srand(time(NULL));
	this->die = new Die();
}

DiceRollingFacility::~DiceRollingFacility() {
	delete this->die;
	this->die = NULL;
	this->diceRolls.clear();

}

const DiceRoll* DiceRollingFacility::getLastRoll() const {
	if (this->diceRolls.empty()) {
		return NULL;
	}
	return this->diceRolls.back();
}

const DiceRoll* DiceRollingFacility::reroll(bool diceToKeep[]) {
	const DiceRoll *diceRoll = this->diceRolls.back();

	// Resolve the dice dicided to be kept.
	Die::Face* roll = new Die::Face[diceRoll->getNumberDice()];
	int rollIndex = 0;
	for (int i = 0; i < diceRoll->getNumberDice(); i++) {
		if (diceToKeep[i]) {
			roll[rollIndex++] = diceRoll->getFaceAt(i);
		}
	}

	// Roll the remaining die that were rejected (if any is rejected)
	if (diceRoll->getNumberDice() - rollIndex > 0) {
		generateRoll(&roll[rollIndex], diceRoll->getNumberDice() - rollIndex);
	}

	const DiceRoll *resolvedDiceRoll = new DiceRoll(roll, diceRoll->getNumberDice());

	this->diceRolls.push_back(resolvedDiceRoll);

	return resolvedDiceRoll;
}

void DiceRollingFacility::generateRoll(Die::Face* roll, int numberDice) const {
	for (int i = 0; i < numberDice; i++) {
		roll[i] = this->die->roll();
	}
}

const DiceRoll* DiceRollingFacility::roll(int numberDice) {
	if (numberDice < 1) {
		throw domain_error("You must at least roll one die");
	}
	// Roll the die the desired number of times
	Die::Face* roll = new Die::Face[numberDice];
	generateRoll(roll, numberDice);

	const DiceRoll* diceRoll = new DiceRoll(roll, numberDice);

	this->diceRolls.push_back(diceRoll);

	return diceRoll;
}