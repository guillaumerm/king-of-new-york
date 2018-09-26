#ifndef KEEP_CARD_H
#define KEEP_CARD_H

#include <string>
#include "GameCard.h"

using namespace std;

class KeepCard : public GameCard {
public:
	KeepCard(string name, string description);
	KeepCard(string name, string description, bool facingUp);
	bool isFacingUp() const;
	void setFacingUp(bool facingUp);
private:
	bool facingUp;
};

#endif
