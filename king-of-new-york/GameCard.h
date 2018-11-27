#ifndef GAME_CARD_H
#define GAME_CARD_H

#include <string>
#include "Card.h"
#include "CardPlayedSubject.h"

using namespace std;

/**
 * @brief Base class for game cards. This class adds the concept of cost to the Cards.
 */
class GameCard: public Card, public CardPlayedSubject {
protected:
	int cost; /**< Cost of the card instance */
public:
	/**
	 * Parameterless constructor
	 */
	GameCard();

	/**
	 * Constructor for GameCard
	 * @param name name of the card
	 * @param description of the card
	 */
	GameCard(string name, string description);

	/**
	 * Constructor for GameCard
	 * @param name name of the card
	 * @param description of the card
	 * @param cost of the card
	 */
	GameCard(string name, string description, int cost);

	/**
	 *	
	 */
	void play();

	/**
	 * Returns the cost of the card
	 * @return card cost
	 */
	int getCost() const;

	/**
	 * Sets the cost of the card.
	 * @param cost cost to be set to the card
	 */
	void setCost(int cost);

	virtual ~GameCard() = 0;
private:
	friend ostream& operator<<(ostream&, const GameCard&);
};

#endif
