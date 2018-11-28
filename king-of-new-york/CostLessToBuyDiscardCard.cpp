#include "CostLessToBuyDiscardCard.h"

CostLessToBuyDiscardCard::CostLessToBuyDiscardCard(string name, string description, int cost, string linkedBorough, int energyCubes, int victoryPoints, int healPoints, int discount): GainPointsDiscardCard(name, description, cost, linkedBorough, energyCubes, victoryPoints, healPoints) {
	this->m_discount = discount;
}

int CostLessToBuyDiscardCard::getCost(string zone)
{
	if (this->getLinkedBorough() == zone) {
		return this->cost - this->m_discount;
	}
	else {
		return this->cost;
	}
	
}

CostLessToBuyDiscardCard::~CostLessToBuyDiscardCard()
{
}
