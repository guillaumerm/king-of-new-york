#include <string>
#include "KeepCard.h"

using namespace std;

bool const DEFAULT_FACING_UP = true;

KeepCard::KeepCard() :KeepCard("", "", 0, DEFAULT_FACING_UP) {};

KeepCard::KeepCard(string name, string description, int cost) : KeepCard(name, description, cost, DEFAULT_FACING_UP) {};

KeepCard::KeepCard(string name, string description, int cost, bool facingUp) : GameCard(name, description, cost) {
	this->facingUp = facingUp;
};

bool KeepCard::isFacingUp() const{
	return this->facingUp;
};

void KeepCard::setFacingUp(bool facingUp) {
	this->facingUp = facingUp;
}

KeepCard::~KeepCard()
{
}

ostream& operator<<(ostream& strm, const KeepCard& card) {
	return strm << "GameCard(name:" << card.name << "; description:" << card.description << "cost:" << card.cost << ")";
}