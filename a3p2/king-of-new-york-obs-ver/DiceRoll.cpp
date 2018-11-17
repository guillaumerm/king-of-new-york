#include "DiceRoll.h"
#include <ostream>

using namespace std;

DiceRoll::DiceRoll() : DiceRoll(new Die::Face[0], 0) {};

DiceRoll::DiceRoll(Die::Face *roll, int numberDice) {
	this->roll = roll;
	this->numberDice = numberDice;
}

DiceRoll::~DiceRoll() {
	delete[] this->roll;
	this->roll = NULL;
}

int DiceRoll::getSumAttack() const {
	return this->getSumFace(Die::Face::A);
}

int DiceRoll::getSumCelebrity() const {
	return this->getSumFace(Die::Face::C);
}

int DiceRoll::getSumDesctruction() const {
	return this->getSumFace(Die::Face::D);
}

int DiceRoll::getSumEnergy() const {
	return this->getSumFace(Die::Face::E);
}

int DiceRoll::getSumHeal() const {
	return this->getSumFace(Die::Face::H);
}

int DiceRoll::getSumOuch() const {
	return this->getSumFace(Die::Face::O);
}

int DiceRoll::getNumberDice() const{
	return this->numberDice;
}

Die::Face DiceRoll::getFaceAt(int dieIndex) const {
	if (dieIndex < 0 || dieIndex >= this->numberDice)
		throw out_of_range("Out of bound index");
	return this->roll[dieIndex];
}

int DiceRoll::getSumFace(Die::Face face) const {
	int sum = 0;
	for (int i = 0; i < this->numberDice; i++) {
		if (this->roll[i] == face) {
			sum++;
		}
	}
	return sum;
}

ostream& operator<<(ostream& strm, const DiceRoll &diceRoll) {
	strm << "DiceRoll(";
	for (int i = 0; i < diceRoll.numberDice; i++) {
		strm << diceRoll.roll[i];
		if (i < diceRoll.numberDice - 1)
			strm << ", ";
	}
	strm << ")";

	return strm;
}