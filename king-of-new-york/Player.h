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
#include "PlayerStateMachine.h"
#include "PlayerStrategy.h"
#include "Subject.h"

class GameMap;

using namespace std;

class PlayerStrategy;

/** 
 * @brief A class which regroups the behavior/action that a player would need to play the game.
 */
class Player: public Subject {
public:
	/** 
	 * Parameterless constructor
	 */
	Player();

	/**
	 * Constructor which init a Player with a MonsterCard
	 * @param monsterCard A pointer to a monsterCard
	 */
	Player(MonsterCard* monsterCard, PlayerStrategy* strategy);

	/**
	 * Constructor which init a Player with a MonsterCard, EnergyCubes and a StartingZone
	 * @param monsterCard A pointer to a monsterCard
	 * @param energyCubes Number of energyCubes initially held by the player
	 * @param startingZone name of the zone in which the player starts from
	 */
	Player(MonsterCard* monsterCard, EnergyCube energyCubes, string startingZone, PlayerStrategy* strategy);

	/**
	 * Constructor which init a Player with a MonsterCard, EnergyCubes and a StartingZone
	 * @param monsterCard A pointer to a monsterCard
	 * @param energyCubes Number of energyCubes initially held by the player
	 * @param startingZone name of the zone in which the player starts from
	 */
	Player(MonsterCard* monsterCard, EnergyCube energyCubes, string startingZone, PlayerStateMachine::PlayerState state, PlayerStrategy* strategy);

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
	const DiceRoll* rollDice(int numberDice);

	/** 
	 * Rolls the desired number of dice. The number of dice should be greater or equal to 1.
	 * @param numberDice number of dice to roll
	 * @throws domain_error if the numberDice is lower than 1.
	 * @return DiceRoll * resulting from the role
	 */
	const DiceRoll* rollDice(bool diceToRoll[]);

	/**
	 * Checks whether the player is currently in the rolling state of his turn.
	 * @return true is rolling, false otherwise
	 */
	bool isRolling() const;

	/**
	 * Checks whether the player is currently in the moving state of his turn.
	 * @return true is moving, false otherwise
	 */
	bool isMoving() const;

	/**
	 * Checks whether the player is currently in the resolving state of his turn.
	 * @return true is resolving, false otherwise
	 */
	bool isRelsoving() const;

	/**
	 * Checks whether the player is currently in the buying state of his turn.
	 * @return true is buying, false otherwise
	 */
	bool isBuying() const;

	/**
	 * Changes the state of the player to the next state if all requires are meant.
	 */
	void endPhase();

	/**
	 * Sets the player state to the start of the state machine for the player to start his/her turn.
	 */
	void startTurn();

	/**
	 * Sets the player state to the end of the state machine for the player to end his/her turn.
	 */
	void endTurn();

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
	void buyCards(unordered_set<GameCard*> cardsToBeBought);

	void executeTurn(GameMap* board, vector<GameCard*> cardsAvailable, int numberOfDice);


	unordered_map<Die::Face, int> getLastResolved();

	const DiceRoll* getLastRoll();

	vector<GameCard*> getHand();

	/**
	 * Checks whether the Player is dead (ie has 0 life points)
	 * @return true if dead, false otherwise
	 */
	bool isDead();

	/**
	 * Checks whether the Player is idle
	 * @return true if idle, false otherwise
	 */
	bool isIdle();

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
	 * Adds a given amount of Energy Cubes.
	 * @param amount amount of Energy Cubes to be added
	 */
	void addEnergyCubes(int amount);

	/**
	 * Remove a give amount of Energy Cubes.
	 * @param amount amount of Energy Cubes to be removed
	 */
	void removeEnergyCubes(int amount);

	/**
	 * Gets the number of Energy Cubes the player has.
	 */
	int getEnergyCubes() const;

	/**
	 * Get the current zone where the player is currently located.
	 */
	string getCurrentZone() const;

	/**
	 * Get the monsters name
	 * @return the name of the monster
	 */
	string getMonster();

	/**
	 * Sets the current zone of the player
	 * @param zone new zone where the player is located
	 */
	void setCurrentZone(string zones);

	void setPlayerStrategy(PlayerStrategy *strategy);
private:
	DiceRollingFacility* diceRollingFacility; /**< Object used to roll and track rolls */
	MonsterCard* monsterCard; /**< Object used to track victory points and life points */
	EnergyCube energyCubes; /**< Currency used by player to buying cards, etc. */
	vector<GameCard*> gameCards; /**< KeepCards/GoalCards currently being held by the player */
	vector<Token*> tokens; /**< Tokens currently being held by the player */
	string currentZone; /**< The zone where the player is currently located */
	PlayerStateMachine state; /**< The state that keeps track of the current state of the player */
	PlayerStrategy* strategy;
	unordered_map<Die::Face, int> lastResolved;
};
#endif
