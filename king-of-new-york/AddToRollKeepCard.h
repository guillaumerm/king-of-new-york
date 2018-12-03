#ifndef ADD_TO_ROLL_KEEP_CARD_H
#define ADD_TO_ROLL_KEEP_CARD_H
#include "KeepCard.h"
#include "Die.h"

/**
 * @brief Keep Card which adds to your result.
 */
class AddToRollKeepCard: public KeepCard {
public:
	/**
	 * Constructor which returns an instance of AddToRollKeepCard
	 * @param name name of the card
	 * @param description description of the effect to the card
	 * @param cost number of energy cubes required to buy the card
	 * @param face face to which the amount is added
	 * @param amount number of added to the result
	 */
	AddToRollKeepCard(string name, string description, int cost, Die::Face face, int amount);

	/**
	 * Get the amount
	 * @returns amount to be added to the result
	 */
	int getAmount();

	/**
	 * Get the Die::Face to which the amount should be added
	 * @returns Die::Face
	 */
	Die::Face getFace();
private:
	Die::Face m_face; /** < Die::Face of the amount to be added*/
	int m_amount; /** < Amount to be added*/
};
#endif
