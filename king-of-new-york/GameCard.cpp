#include "GameCard.h"

using namespace std;

int const DEFAULT_GAME_CARD_COST = 0;

GameCard::GameCard() :Card() {
	this->setCost(DEFAULT_GAME_CARD_COST);
};

GameCard::GameCard(string name, string description) : GameCard(name, description, DEFAULT_GAME_CARD_COST) {};

GameCard::GameCard(string name, string description, int cost) : Card(name, description) {
	try {
		this->setCost(cost);
	}
	catch (exception& e) {
		throw e;
	}
}

void GameCard::play() {
	this->notify(this->name, this->description, this->cost);
}

void GameCard::setCost(int cost) {
	if (cost < 0)
		throw new domain_error("Cost of a card must be >= 0");
	this->cost = cost;
}

GameCard::~GameCard()
{
}

int GameCard::getCost() const {
	return this->cost;
}

ostream& operator<<(ostream &strm, const GameCard &card) {
	return strm << "GameCard(name:" << card.name << "; description:" << card.description << ";cost:"<< card.cost <<")";
}