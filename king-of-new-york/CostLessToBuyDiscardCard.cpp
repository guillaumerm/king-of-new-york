#include "CostLessToBuyDiscardCard.h"

CostLessToBuyDiscardCard::CostLessToBuyDiscardCard(string zone, int discount) {
	this->m_zone = zone;
	this->m_discount = discount;
}

int CostLessToBuyDiscardCard::getCost(string zone)
{
	return this->cost - this->m_discount;
}
