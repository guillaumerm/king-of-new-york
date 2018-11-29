#include "GoalCard.h"

using namespace std;

GoalCard::GoalCard(string name, string description): GameCard(name, description, NULL) {};

ostream& operator<<(ostream& strm, const GoalCard& card) {
	return strm << "GameCard(name:" << card.name << "; description:" << card.description << ")";
}
