#ifndef DISCARD_CARD_H
#define DISCARD_CARD_H

#include <string>
#include "GameCard.h"

using namespace std;
/**
 * @brief A specific class of GameCard which will need to be discarded once bought.
 */
class DiscardCard : public GameCard {
public:
	static const string DEFAULT_BOROUGH; /**< Default linked borough */
	/**
	 * Parameterless constructor
	 */
	DiscardCard();

	/**
	 * Constructor of DiscardCard that does not have a linked borough.
	 * @param name name of the DiscardCard
	 * @param description description of the DiscardCard
	 * @param cost cost of the DiscardCard
	 */
	DiscardCard(string name, string description, int cost);

	/** 
	 * Constructor of DiscardCard that links the Card to a Borrow
	 * @param name name of the DiscardCard
	 * @param description description of the DiscardCard
	 * @param cost cost of the DiscardCard
	 * @param linkedBorough borough to which the DiscardCard is linked
	 */
	DiscardCard(string name, string description, int cost, string linkedBorough);

	/**
	 * Get the linked borough of the DiscardCard
	 * @return the linked Borough, empty string if not linked to a borough
	 */
	string getLinkedBorough() const;
private:
	string linkedBorough; /**< Linked of the DiscardCard */
	friend ostream& operator<<(ostream&, const DiscardCard&);
};
#endif
