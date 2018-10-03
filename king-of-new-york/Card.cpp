#include <string>
#include <exception>
#include <iostream>

#include "Card.h"

using namespace std;

string const DEFAULT_CARD_NAME = "";
string const DEFAULT_CARD_DESCRIPTION = "";

Card::Card() :Card(DEFAULT_CARD_NAME, DEFAULT_CARD_DESCRIPTION) {};

Card::Card(string name, string description) {
	try {
		this->setName(name);
		this->setDescription(description);
	}
	catch (exception& e){
		cerr << e.what() << endl;
	}
}

void Card::setName(string name) {
	if (name.length() <= 0) {
		throw new domain_error("Size of name must be greater than 0");
		exit(1);
	}
	this->name = name;
}

void Card::setDescription(string description) {
	if (description.length() <= 0) {
		throw new domain_error("Size of description must be greater than 0");
		exit(1);
	}
	this->description = description;
}

string Card::getName() const {
	return this->name;
}

/**
	Obtain the current description of the Card instance.
	@return
*/
string Card::getDescription() const {
	return this->description;
}

ostream& operator<<(ostream &strm, const Card &card) {
	return strm << "Card(" << card.name << "; " << card.description << ")";
}