#ifndef GAIN_POINTS_DISCARD_CARD_H
#define GAIN_POINTS_DISCARD_CARD_H
#include "DiscardCard.h"

/**
 * @brief Type of DiscardCard which when played points are gained.
 */
class GainPointsDiscardCard : public DiscardCard {
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
	GainPointsDiscardCard(string name, string description, int cost, string linkedBorough, int energyCubes, int victoryPoints, int healPoints);

	/**
	 * Amount of energy cubes gained when played
	 * @returns number of energy cubes gained
	 */
	int getEnergyCubes();

	/**
	 * Amount of victory points gained when played
	 * @returns number of victory points gained
	 */
	int getVictoryPoints();

	/**
	 * Amount of health points gained when played
	 * @returns number of health points gained
	 */
	int getHealPoints();
private:
	int m_energyCubes; /** < Number of energy cubes */
	int m_victoryPoints; /** < Number of victory points */
	int m_healPoints; /** < Number of health points */
};
#endif