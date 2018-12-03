#ifndef CARD_PLAYED_VIEW_H
#define CARD_PLAYED_VIEW_H
#include <unordered_map>
#include <string>
#include <iostream>
#include "CardPlayedInterface.h"
#include "CardPlayedObserver.h"

/**
 * @brief View which keep track of card played during the player turn
 */
class CardPlayedView: public CardPlayedInterface, public CardPlayedObserver {
public:
	/**
	 * Function called when CardPlayed subject changes states. This function keeps track of the played card.
	 * @param name Name of the card
	 * @param description Effects of the card when played
	 * @param cost Amount of Energy Cubes required to buy this card
	 */
	void update(std::string name, std::string description, int cost);

	/**
	 * Display the cards played in the turn.
	 */
	void show();

	/**
	 * Clear the cards played during the turn.
	 */
	void clear();
private:
	std::unordered_map<std::string, std::string> cardsPlayed; /** < Cards played during the turn */
};
#endif
