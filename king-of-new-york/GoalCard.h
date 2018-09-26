#ifndef GOAL_CARD_H
#define GOAL_CARD_H

#include <string>
#include "GameCard.h"

class GoalCard : public GameCard {
public:
	GoalCard(string name, string description);
};
#endif