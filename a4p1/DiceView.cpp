#include "DiceView.h"

void DiceView::update()
{
	this->show();
}

void DiceView::show() {
	cout << "-------------------Dice Roll Details-------------------" << endl;
	cout << "The player rolled:" << endl;
	const DiceRoll* currentRoll = this->currentRollFacil->getLastRoll();
	if (currentRoll->getSumAttack() > 0)
	{
		cout << currentRoll->getSumAttack() << " Attack!" << endl;
	}
	if (currentRoll->getSumCelebrity() > 0)
	{
		cout << currentRoll->getSumCelebrity() << " Celebrity" << endl;
	}
	if (currentRoll->getSumDesctruction() > 0)
	{
		cout << currentRoll->getSumDesctruction() << " Destruction" << endl;
	}
	if (currentRoll->getSumEnergy() > 0)
	{
		cout << currentRoll->getSumEnergy() << " Energy" << endl;
	}
	if (currentRoll->getSumHeal() > 0)
	{
		cout << currentRoll->getSumHeal() << " Healing" << endl;
	}
	if (currentRoll->getSumOuch() > 0)
	{
		cout << currentRoll->getSumOuch() << " Ouch" << endl;
	}

	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	
}

void DiceView::setCurrentFacility(DiceRollingFacility * rollFacility)
{
	this->currentRollFacil = rollFacility;
}