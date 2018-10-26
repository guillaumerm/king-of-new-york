#include "DiceRollingFacility.h"
#include "DiceRoll.h"
#include <iostream>

int main25() {
	DiceRollingFacility diceRollingFacility1;
	DiceRollingFacility diceRollingFacility2;
	const DiceRoll *roll1 = diceRollingFacility1.roll(10);
	const DiceRoll *roll2 = diceRollingFacility2.roll(10);
	cout << *roll1 << endl;
	cout << *roll2 << endl;
	delete roll1;
	delete roll2;
	system("pause");
	return 0;
}