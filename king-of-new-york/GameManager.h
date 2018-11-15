#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "Player.h";
#include "Deck.h"
#include "Observer.h"

using namespace std;

class GameManager: public Observer {
public:
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

	void update();

	Player * currentPlayer;
private:
	
};
#endif
