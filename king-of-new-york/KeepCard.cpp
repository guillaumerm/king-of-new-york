#include <string>
#include "KeepCard.h"

using namespace std;

bool const DEFAULT_FACING_UP = true;

KeepCard::KeepCard(string name, string description) : KeepCard(name, description, DEFAULT_FACING_UP) {};

KeepCard::KeepCard(string name, string description, bool facingUp) : GameCard(name, description) {
	this->facingUp = facingUp;
};

bool KeepCard::isFacingUp() const{
	return this->facingUp;
};

void KeepCard::setFacingUp(bool facingUp) {
	this->facingUp = facingUp;
}