#include <string>
#include "GameCard.h"
#include "DiscardCard.h"

using namespace std;

const string DiscardCard::DEFAULT_BOROUGH = "";

DiscardCard::DiscardCard(string name, string description, int cost) :DiscardCard(name, description, cost, DEFAULT_BOROUGH) {};

DiscardCard::DiscardCard(string name, string description, int cost, string linkedBorough):GameCard(name, description, cost) {
	this->linkedBorough = linkedBorough;
};

string DiscardCard::getLinkedBorough() const {
	return this->linkedBorough;
};

ostream& operator<<(ostream &strm, const DiscardCard &card) {
	return strm << "DiscardCard (name=" << card.getName() << "; description=" << card.getDescription() << "; cost=" << card.getCost() << "; linkedBorough=" << card.getLinkedBorough() << ")";
}