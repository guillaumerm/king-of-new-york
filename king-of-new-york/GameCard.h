#ifndef GAME_CARD_H
#define GAME_CARD_H

#include <string>
#include "Card.h"

using namespace std;

class GameCard: public Card {
protected:
	int cost;
public:
	GameCard();
	GameCard(string name, string description);
	GameCard(string name, string description, int cost);
	int getCost() const;
	void setCost(int cost);
private:
	friend ostream& operator<<(ostream&, const GameCard&);
};

#endif
