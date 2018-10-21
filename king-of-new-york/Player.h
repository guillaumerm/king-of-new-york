#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "GameMap.h"
#include "MonsterCard.h"
#include "GameCard.h"
#include "DiceRollingFacility.h"
#include "EnergyCube.h"
#include "Token.h"

class GameMap;

using namespace std;

/** 
 * @brief A class which regroups the behavior/action that a player would need to play the game.
 */
class Player {
public:
	/** 
	 * Parameterless constructor
	 */
	Player();

	/**
	 * Constructor which init a Player with a MonsterCard, EnergyCubes and a StartingZone
	 * @param monsterCard A pointer to a monsterCard
	 * @param energyCubes Number of energyCubes initially held by the player
	 * @param startingZone name of the zone in which the player starts from
	 */
	Player(MonsterCard* monsterCard, EnergyCube energyCubes, string startingZone);

	/**
	 * A destructor for Player
	 */
	~Player();

	/** 
	 * Rolls the desired number of dice. The number of dice should be greater or equal to 1.
	 * @param numberDice number of dice to roll
	 * @throws domain_error if the numberDice is lower than 1.
	 * @return DiceRoll * resulting from the role
	 */
	const DiceRoll* rollDice(bool diceToRoll[], int numberDice);

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
	 * Checks whether the Player is dead (ie has 0 life points)
	 * @return true if dead, false otherwise
	 */
	bool isDead();

	/**
	 * Obtain the victory points of the player
	 * @return number of victory points
	 */
	int getVictoryPoints() const;

	/**
	 * Obtain the life points of the Player
	 * @return number of life points
	 */
	int getLifePoints() const;

	/** 
	 * Add victory points to the Player. If the amount exceeds the maximum number the max is set as the current value.
	 */
	void addVictoryPoints(int victoryPoints);

	/**
	 * Add life points to the Player. If the amount exceeds the maximum number the max is set as the current value.
	 */
	void addLifePoints(int lifePoints);

	/**
	 * Remove victory points from the Player. If the amount exceeds the minimum number the min is set as the current value.
	 */
	void removeVictoryPoints(int victoryPoints);

	/**
	 * Remove life points from the Player. If the amount exceeds the minimum number the min is set as the current value.
	 */
	void removeLifePoints(int lifePoints);

	/**
	 * Get the current zone where the player is currently located.
	 */
	string getCurrentZone() const;
private:
	DiceRollingFacility* diceRollingFacility; /**< Object used to roll and track rolls */
	MonsterCard* monsterCard; /**< Object used to track victory points and life points */
	EnergyCube energyCubes; /**< Currency used by player to buying cards, etc. */
	vector<GameCard*> gameCards; /**< KeepCards/GoalCards currently being held by the player */
	vector<Token*> tokens; /**< Tokens currently being held by the player */
	string currentZone; /**< The zone where the player is currently located */
	/**
	 * Sets the current zone of the player
	 * @param zone new zone where the player is located
	 */
	void setCurrentZone(string zones);
};
#endif
