#ifndef DICE_ROLLING_FACILITY_H
#define DICE_ROLLING_FACILITY_H
#include "DiceRoll.h"
#include "Die.h"
#include <vector>

using namespace std;

class DiceRollingFacility {
public:
	DiceRollingFacility();
	~DiceRollingFacility();
	const DiceRoll* roll(int);
	const DiceRoll* getLastRoll() const;
	const DiceRoll* resolve(bool[]);
private:
	Die* die;
	void generateRoll(Die::Face*, int) const;
	vector<const DiceRoll*> diceRolls;
};
#endif