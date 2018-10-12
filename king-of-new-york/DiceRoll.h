#ifndef DICE_ROLL_H
#define DICE_ROLL_H
#include "Die.h"
#include <ostream>

using namespace std;

/**
 * @brief Class that is used create records of dice rolls.
 */
class DiceRoll {
public:
	/**
	 * Parameterless DiceRoll constructor.
	 */
	DiceRoll();

	/**
	 * A constructor which creates a roll with the disered dice rolls.
	 * @param Die::Face* array containing the rolls
	 */
	DiceRoll(Die::Face*, int);

	/**
	 * Destroys the current instance
	 */
	~DiceRoll();

	/**
	 * Counts the number of Attack (A) in the roll.
	 * @return the count of Attack
	 */
	int getSumAttack() const;

	/**
	 * Counts the number of Celebrity (C) in the roll.
	 * @return the count of Celebrity
     */
	int getSumCelebrity() const;

	/**
	 * Counts the number of Destruction (D) in the roll.
	 * @return the count of Destruction
	 */
	int getSumDesctruction() const;

	/**
	 * Counts the number of Energy (E) in the roll.
	 * @return the count of Energy
	 */
	int getSumEnergy() const;

	/**
	 * Counts the number of Heal (H) in the roll.
	 * @return the count of Heal
	 */
	int getSumHeal() const;

	/**
	 * Counts the number of Ouch! (O) in the roll.
	 * @return the count of Ouch
	 */
	int getSumOuch() const;

	/**
	 * Get the number of dice in the roll.
	 * @return the number of dice
	 */
	int getNumberDice() const;

	/**
	 * Get the die face at roll index.
	 * @param dieIndex index of the die
	 * @return the Die::Face at given index
	 */
	Die::Face getFaceAt(int dieIndex) const;
private:
	int numberDice; /**< Number of dice that the roll contains */
	Die::Face* roll; /**< Faces that compose this dice roll */

	/**
	 * Counts the number a die face appears in the roll
	 * @param face the die to count
	 * @return count of the face in the dice roll.
	 */
	int getSumFace(Die::Face face) const;
	friend ostream& operator<<(ostream& strm, const DiceRoll&);
};

ostream& operator<<(ostream& strm, const Die::Face);
#endif
