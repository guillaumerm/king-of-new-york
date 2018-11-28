#include "GainPointsDiscardCard.h"

GainPointsDiscardCard::GainPointsDiscardCard(string name, string description, int cost, string linkedBorough, int energyCubes, int victoryPoints, int healPoints): DiscardCard(name, description, cost, linkedBorough)
{
	this->m_energyCubes = energyCubes;
	this->m_victoryPoints = victoryPoints;
	this->m_healPoints = healPoints;
}

int GainPointsDiscardCard::getEnergyCubes()
{
	return this->m_energyCubes;
}

int GainPointsDiscardCard::getVictoryPoints()
{
	return this->m_victoryPoints;
}

int GainPointsDiscardCard::getHealPoints()
{
	return this->m_healPoints;
}
