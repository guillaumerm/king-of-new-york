#ifndef DICE_ROLLING_FACILITY_H
#define DICE_ROLLING_FACILITY_H
#include "DiceRoll.h"
#include "Die.h"
#include <vector>

using namespace std;

/**
 * @brief Facility used to roll dice. It also keeps record of the previously rolled dice.
 */
class DiceRollingFacility {
public:
	/**
	 * Parameterless constructor for DiceRollingFacility
	 */
	DiceRollingFacility();

	/**
	 * Destructor for DiceRollingFacility
	 */
	~DiceRollingFacility();

	/**
	 * Rolls a dice roll of the desired number of dice. It also records this roll.
	 * @param numberDice number of dice to be rolled
	 * @return the DiceRoll rolled
	 */
	const DiceRoll* roll(int numberDice);

	/**
 * Rolls a dice roll of the desired number of dice. It also records this roll.
 * @param numberDice number of dice to be rolled
 * @return the DiceRoll rolled
 */
	const DiceRoll* reroll(bool diceToKeep[]);

	/**
	 * Returns the last DiceRoll added to the DiceRollingFacility
	 * @return the last DiceRoll * rolled
	 */
	const DiceRoll* getLastRoll() const;
private:
	Die* die; /**< Die used to roll random Die::Face */
	/**
	 * Sets random Die::Face for the array of the specified length.
	 * @param roll Die::Face * that will hold the Die::Face
	 * @param length length of the array roll
	 */
	void generateRoll(Die::Face *roll, int length) const;

	/**
	 * Data structure that records the previously DiceRoll rolled
	 */
	vector<const DiceRoll*> diceRolls;
};
#endif