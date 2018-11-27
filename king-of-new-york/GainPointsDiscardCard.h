#ifndef GAIN_POINTS_DISCARD_CARD_H
#define GAIN_POINTS_DISCARD_CARD_H
#include "Player.h"
#include "DiscardCard.h"
class GainPointsDiscardCard : public DiscardCard {
public:
	GainPointsDiscardCard(int energyCubes, int victoryPoints, int healPoints);

	void addPoints(Player *player);
private:
	int m_energyCubes;
	int m_victoryPoints;
	int m_healPoints;
};
#endif