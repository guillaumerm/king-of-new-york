#ifndef DICE_ROLL_H
#define DICE_ROLL_H
#include "Die.h"
#include <ostream>

using namespace std;

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
	friend ostream& operator<<(ostream& strm, const DiceRoll&);
};

ostream& operator<<(ostream& strm, const Die::Face);
#endif
