#ifndef ADD_TO_ROLL_KEEP_CARD_H
#define ADD_TO_ROLL_KEEP_CARD_H
#include "KeepCard.h"
#include "Die.h"

class AddToRollKeepCard: public KeepCard {
public:
	AddToRollKeepCard(string name, string description, int cost, Die::Face face, int amount);
	int getAmount();
	Die::Face getFace();
private:
	Die::Face m_face;
	int m_amount;
};
#endif
