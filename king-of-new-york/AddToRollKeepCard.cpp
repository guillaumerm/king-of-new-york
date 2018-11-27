#include "AddToRollKeepCard.h"

AddToRollKeepCard::AddToRollKeepCard(string name, string description, int cost, Die::Face face, int amount): KeepCard(name, description, cost)
{
	this->m_face = face;
	this->m_amount = amount;
}

Die::Face AddToRollKeepCard::getFace() {
	return this->m_face;
}

int AddToRollKeepCard::getAmount() {
	return this->m_amount;
}
