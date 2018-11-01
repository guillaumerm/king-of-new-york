#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "Player.h";

void executeStart();
void executeStartupPhase();

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
void dealNewCardsToBuy(Player &player, vector<GameCard> cardsAvailable);
void executeMovePhase(Player *player, GameMap *map);
#endif
