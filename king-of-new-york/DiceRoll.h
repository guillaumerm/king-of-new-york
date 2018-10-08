#ifndef DICE_ROLL_H
#define DICE_ROLL_H
#include "Die.h"

class DiceRoll {
public:
	DiceRoll();
	DiceRoll(Die::Face*, int);
	int getSumAttack() const;
	int getSumCelebrity() const;
	int getSumDesctruction() const;
	int getSumEnergy() const;
	int getSumHeal() const;
	int getSumOuch() const;
	int getNumberDice() const;
	Die::Face getFaceAt(int ) const;
private:
	int numberDice;
	Die::Face* roll;
	int getSumFace(Die::Face face) const;
};
#endif
