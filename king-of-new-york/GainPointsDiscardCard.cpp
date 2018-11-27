#include "GainPointsDiscardCard.h"
#include "Player.h"

GainPointsDiscardCard::GainPointsDiscardCard(int energyCubes, int victoryPoints, int healPoints)
{
	this->m_energyCubes = energyCubes;
	this->m_victoryPoints = victoryPoints;
	this->m_healPoints = healPoints;
}

void GainPointsDiscardCard::addPoints(Player * player)
{
	player->addEnergyCubes(this->m_energyCubes);
	player->addLifePoints(this->m_healPoints);
	player->addVictoryPoints(this->m_victoryPoints);
}
