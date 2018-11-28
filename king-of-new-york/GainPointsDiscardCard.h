#ifndef GAIN_POINTS_DISCARD_CARD_H
#define GAIN_POINTS_DISCARD_CARD_H
#include "DiscardCard.h"

class GainPointsDiscardCard : public DiscardCard {
public:
	GainPointsDiscardCard(string name, string description, int cost, string linkedBorough, int energyCubes, int victoryPoints, int healPoints);

	int getEnergyCubes();
	int getVictoryPoints();
	int getHealPoints();
private:
	int m_energyCubes;
	int m_victoryPoints;
	int m_healPoints;
};
#endif