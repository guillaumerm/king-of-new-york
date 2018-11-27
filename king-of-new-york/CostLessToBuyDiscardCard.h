#ifndef COST_LESS_TO_BUY_DISCARD_CARD_H
#define COST_LESS_TO_BUY_DISCARD_CARD_H
#include "GainPointsDiscardCard.h"
#include "CostLessToBuyDiscardCard.h"
#include "Player.h"
class CostLessToBuyDiscardCard : public GainPointsDiscardCard {
public:
	CostLessToBuyDiscardCard(string zone, int discount);
	int getCost(string zone);
private:
	string m_zone;
	int m_discount;
};
#endif
