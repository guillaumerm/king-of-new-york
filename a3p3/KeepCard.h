#ifndef KEEP_CARD_H
#define KEEP_CARD_H

#include <string>
#include "GameCard.h"

using namespace std;

/**
 * @brief A specification of the base class Card. Introduces the concept of facing as cards can be facing down by the game rule.
 */
class KeepCard : public GameCard {
public:
	/**
	 * Parameterless contructor for KeepCard
	 */
	KeepCard();

	/** 
	 * A constructor which init a KeepCard with a given given, description and cost
	 * @param name name of the KeepCard
	 * @param description description of the KeepCard
	 * @param cost cost of buying the card
	 */
	KeepCard(string name, string description, int cost);

	/** 
	 * A constructor which init a KeepCard with a given given, description and cost
	 * @param name name of the KeepCard
	 * @param description description of the KeepCard
	 * @param cost cost of buying the card
	 * @param facingUp bool which states if the card is facing up or down
	 */
	KeepCard(string name, string description, int cost, bool facingUp);

	/**
	 * Returns the facing state of the KeepCard
	 * @return true if facing up, false otherwise
	 */
	bool isFacingUp() const;

	/**
	 * Changes the facing state of the KeepCard
	 * @param facingUp bool which indicates if the KeepCard will be facing up
	 */
	void setFacingUp(bool facingUp);

	~KeepCard();
private:
	bool facingUp; /**< Value which indicates if the card is facing up*/
	friend ostream& operator<<(ostream& strm, const KeepCard&);
};

#endif
