#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card {
protected:
	string name; /**< Name of the card*/
	string description; /**< Description of the card*/
public:
	/**
	 * Parameterless constructor for cards.
	 * Sets the name and description to the empty string.
	 */
	Card();
	/**
	 * A card constructor taking a name and description
	 * @param name name of the card
	 * @param description  how to play the card and its effect
	 */
	Card(string name, string description);

	/**
	 * Get the name of the card.
	 * @return name of the card
	 */
	string getName() const;

	/**
	 * Get the name of the card.
	 * @return name of the card
	 */
	string getDescription() const;

	/**
	 * Set the name of the card.
	 * @param name name of the card
	 */
	void setName(string name);

	/**
	 * Set the description of the card. (ie. how to play the card and its effect)
	 * @param description description of the card
	 */
	void setDescription(string description);
	friend ostream& operator<<(ostream&, const Card&);
};
#endif