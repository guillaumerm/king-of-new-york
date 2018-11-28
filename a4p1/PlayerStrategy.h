#ifndef PLAYER_STRATEGY_H
#define PLAYER_STRATEGY_H
#include "DiceRollingStrategy.h"
#include "DiceResolvingStrategy.h"
#include "MovingStrategy.h"
#include "BuyingCardsStrategy.h"
#include "Deck.h"

using namespace std;

class BuyingCardsStrategy;
class DiceRollingStrategy;
class DiceResolvingStrategy;
class MovingStrategy;
class Player;
class GameMap;
/**
 * @brief An interface which group a DiceRollingStrategy, DiceResolvingStrategy, MovingStrategy and BuyingCardsStrategy.
 */
class PlayerStrategy {
public:
	/**
	 * Paramterless construct.
	 */
	~PlayerStrategy();

	/**
	 * Sets the DiceRollingStrategy of this instance of PlayerStrategy
	 */
	void setDiceRollingStrategy(DiceRollingStrategy *diceRollingStrategy);

	/**
	 * Sets the DiceResolvingStrategy of this instance of PlayerStrategy
	 */
	void setDiceResolvingStrategy(DiceResolvingStrategy *diceResolvingStrategy);

	/**
	 * Sets the MovingStrategy of this instance of PlayerStrategy
	 */
	void setMovingStrategy(MovingStrategy *movindStrategy);

	/**
	 * Sets the BuyingCardsStrategy of this instance of PlayerStrategy
	 */
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

	/**
	 * Function used to execute the buy card phase
	 */
	void executeBuyCardsPhase(Player &player, vector<GameCard*> *cardsAvailable, Deck<GameCard*>* deckOfCards);

	/**
	 * Function which executes dealing new cards available to buy at the cost of two(2) energy cubes
	 * @param player player which is dealing new cards.
	 * @param cardsAvailable cards currently available to buy
	 */
	void dealNewCardsToBuy(Player &player, vector<GameCard> cardsAvailable) {};
private:
	DiceRollingStrategy *diceRollingStrategy;  /** < DiceRollingStrategy of the PlayerStrategy */
	DiceResolvingStrategy *diceResolvingStrategy; /** < DiceRollingStrategy of the PlayerStrategy */
	MovingStrategy *movingStrategy; /** < DiceRollingStrategy of the PlayerStrategy */
	BuyingCardsStrategy *buyingCardStrategy; /** < DiceRollingStrategy of the PlayerStrategy */
};
#endif
