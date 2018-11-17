#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H
#include "Player.h"
#include "DiceRollStrategy.h"

class ComputerPlayer : public Player {
public:
	/**
	* Resolves the last roll. That is decide which dice to keep and which to reroll. The resolution must be the same size as the previous roll.
	* @param resolution array of bool, true to keep the die, false to reroll.
	* @return the new resolved roll
	*/
	const unordered_map<Die::Face, int> resolveDice(unordered_set<Die::Face> order);

	/**
	 * Move a Player from one zone to another zone
	 * @param gameMap the current instance of the gameBoard
	 * @param destinationZone name of the zone where the player wants to move
	 */
	void move(GameMap *gameMap, string destinationZone);

	/**
	 * Buy given cards.
	 * @throws exception if the Player does not have enough EnergyCubes to buy the card
	 * @param cards array of card being bought by the player
	 * @param numCardsBought number of cards being bought
	 */
	void buyCards(GameCard* cards, int numCardsBought);

	/**
	* Rolls the desired number of dice. The number of dice should be greater or equal to 1.
	* @param numberDice number of dice to roll
	* @throws domain_error if the numberDice is lower than 1.
	* @return DiceRoll * resulting from the role
	*/
	const DiceRoll* rollDice(int numberDice);

	/**
	 * Rolls the desired number of dice. The number of dice should be greater or equal to 1.
	 * @param numberDice number of dice to roll
	 * @throws domain_error if the numberDice is lower than 1.
	 * @return DiceRoll * resulting from the role
	 */
	const DiceRoll* rollDice(bool diceToRoll[]);
private:
	DiceRollStrategy* diceRollStrategy;
};
#endif
