#ifndef PLAYER_STRATEGY_H
#define PLAYER_STRATEGY_H
#include "DiceRollingStrategy.h"
#include "DiceResolvingStrategy.h"
#include "MovingStrategy.h"
#include "BuyingCardsStrategy.h"

using namespace std;

class BuyingCardsStrategy;
class DiceRollingStrategy;
class DiceResolvingStrategy;
class MovingStrategy;
class Player;
class GameMap;

class PlayerStrategy {
public:
	~PlayerStrategy();

	void setDiceRollingStrategy(DiceRollingStrategy *diceRollingStrategy);
	void setDiceResolvingStrategy(DiceResolvingStrategy *diceResolvingStrategy);
	void setMovingStrategy(MovingStrategy *movindStrategy);
	void setBuyingCardsStrategy(BuyingCardsStrategy *buyingCardsStrategy);

	/**
	* Function used to execute the roll dice phase
	* @param player player which is executing the roll dice phase
	* @param numberOfDice number of dice being rolled in this dice phase
	*/
	void executeRollDicePhase(Player &player, int numberOfDice);

	/**
	 * Function used to execute the dice resolution phase
	 * @param player player whic is executing the resolve dice phase
	 */
	void executeMovePhase(Player *player, GameMap *map);

	/**
	 * Function used to execute the dice resolution phase
	 * @param player player whic is executing the resolve dice phase
	 */
	void executeResolveDicePhase(Player &player);


	void executeBuyCardsPhase(Player &player, vector<GameCard*> cardsAvailable);

	/**
	 * Function which executes dealing new cards available to buy at the cost of two(2) energy cubes
	 * @param player player which is dealing new cards.
	 * @param cardsAvailable cards currently available to buy
	 */
	void dealNewCardsToBuy(Player &player, vector<GameCard> cardsAvailable) {};

	/**
	 * Function used to execute the move phase.
	 * @param player player being moved
	 * @param map the map which the player is currently situated.
	 */
	//void executeMovePhase(Player *player, GameMap *map);
private:
	DiceRollingStrategy *diceRollingStrategy;
	DiceResolvingStrategy *diceResolvingStrategy;
	MovingStrategy *movingStrategy;
	BuyingCardsStrategy *buyingCardStrategy;
};
#endif
