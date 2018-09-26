#include <string>
#include "GameCard.h"
#include "DiscardCard.h"

using namespace std;

string const DEFAULT_BOROUGH = "";

DiscardCard::DiscardCard(string name, string description, int cost) :DiscardCard(name, description, cost, DEFAULT_BOROUGH) {};

DiscardCard::DiscardCard(string name, string description, int cost, string linkedBorough):GameCard(name, description, cost) {
	this->linkedBorough = linkedBorough;
};

string DiscardCard::getLinkedBorough() const {
	return this->linkedBorough;
};