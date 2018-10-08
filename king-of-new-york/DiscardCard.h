#ifndef DISCARD_CARD_H
#define DISCARD_CARD_H

#include <string>
#include "GameCard.h"

using namespace std;

class DiscardCard : public GameCard {
public:
	DiscardCard(string name, string description, int cost);
	DiscardCard(string name, string description, int cost, string linkedBorrow);
	string getLinkedBorough() const;
private:
	string linkedBorough;
	friend ostream& operator<<(ostream&, const DiscardCard&);
};
#endif
