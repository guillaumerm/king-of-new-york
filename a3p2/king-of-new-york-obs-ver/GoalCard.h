#ifndef GOAL_CARD_H
#define GOAL_CARD_H

#include <string>
#include "GameCard.h"

/**
 * @brief A specific class of GameCard which has special properties.
 */
class GoalCard : public GameCard {
public:
	/**
	 * A constructor which init the GoalCard with a name and description
	 * @param name name of the card
	 * @param description description of the card
	 */
	GoalCard(string name, string description);
private:
	friend ostream& operator<<(ostream&, const GoalCard&);
};
#endif