#include "DiceRoll.h"

DiceRoll::DiceRoll() : DiceRoll(new Die::Face[0], 0) {};

DiceRoll::DiceRoll(Die::Face *roll, int numberDice) {
	this->roll = roll;
	this->numberDice = numberDice;
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