#ifndef COST_LESS_TO_BUY_DISCARD_CARD_H
#define COST_LESS_TO_BUY_DISCARD_CARD_H
#include "GainPointsDiscardCard.h"

class GainPointsDiscardCard;

class CostLessToBuyDiscardCard : public GainPointsDiscardCard {
public:
	CostLessToBuyDiscardCard(string name, string description, int cost, string linkedBorough, int energyCubes, int victoryPoints, int healPoints, int discount);
	int getCost(std::string zone);
	~CostLessToBuyDiscardCard();
private:
	int m_discount;
};
#endif
