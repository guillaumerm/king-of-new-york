#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "Player.h";
#include "Deck.h"

/**
 * Creates all component requires for the game.
 * @param map map being created
 * @param playerList list of players currently playing the game
 * @param deckOfCards the deck of GameCards
 */
void executeStart(GameMap& map, vector<Player*>& playerList, Deck<GameCard*>& deckOfCards);

/**
 * Set ups the game to be ready to play.
 * @param map
 * @param playerList the players
 */
int* executeStartupPhase(GameMap* map, vector<Player*>* playerList);

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


void executeBuyCardsPhase(Player &player, vector<GameCard> cardsAvailable);

/**
 * Function which executes dealing new cards available to buy at the cost of two(2) energy cubes
 * @param player player which is dealing new cards.
 * @param cardsAvailable cards currently available to buy
 */
void dealNewCardsToBuy(Player &player, vector<GameCard> cardsAvailable);

/**
 * Function used to execute the move phase.
 * @param player player being moved
 * @param map the map which the player is currently situated.
 */
void executeMovePhase(Player *player, GameMap *map);
#endif
