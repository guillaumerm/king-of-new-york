#ifndef COST_LESS_TO_BUY_DISCARD_CARD_H
#define COST_LESS_TO_BUY_DISCARD_CARD_H
#include "GainPointsDiscardCard.h"

class GainPointsDiscardCard;

/**
 * @brief Type of DiscardCard which when played points are gained and it cost less in certain borough.
 */
class CostLessToBuyDiscardCard : public GainPointsDiscardCard {
public:
	/**
	 * Constructor which returns an instance of the GainPointsDiscardCard
	 * @param name Name of the card
	 * @param description Description of the effects of the card
	 * @param linkedBorough Name of the which the effect is linked
	 * @param energyCubes Amount of energy cubes gained when played
	 * @param victoryPoints Amount of victory points gained when played
	 * @param healPoints Amount of health points gained when played
	 */
	CostLessToBuyDiscardCard(string name, string description, int cost, string linkedBorough, int energyCubes, int victoryPoints, int healPoints, int discount);

	/**
	 * Gets the cost for a particular zone
	 * @returns the cost of the card
	 */
	int getCost(std::string zone);

	/**
	 * Destructor
	 */
	~CostLessToBuyDiscardCard();
private:
	int m_discount; /** < Discount to be applied to the cost */
};
#endif
