#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "Player.h";
#include "Deck.h"
#include "GameManager.h"
#include "Card.h"
#include "DiscardCard.h"
#include "KeepCard.h"
#include "GameMapLoader.h"
#include "PieceManager.h"
#include "Util.h"
#include "GameStatisticView.h"
#include "PhaseView.h"
#include "AggresivePlayerStrategyBuilder.h"
#include "ModeratePlayerStrategyBuilder.h"
#include "InteractivePlayerStrategyBuilder.h"
#include "PlayerStrategyDirector.h"
#include "CardPlayedView.h"
#include "DiceView.h"

using namespace std;

/**
 * @brief Main controller from controlling the view and the models.
 */
class GameManager {
public:
	static const int NUMBER_OF_CARDS;

	GameManager();

	~GameManager();
	
	/**
	* Creates all component requires for the game.
	*/
	void executeStart();

	/**
	* Set ups the game to be ready to play.
	*/
	void executeStartupPhase();

	/**
	 * Returns the player that has won.
	 * @return Player instance that has won, else NULL
	 */
	Player *hasWon();

	/**
	 * Initiates the main game loop.
	 */
	void play();
private:
	vector<GameCard*>* cardsAvailable; /** < GameCards available to buy */
	Player* currentPlayer; /** < Player who is currently playing */
	GameStatisticView* statisticView; /** < Instance of a GameStatisticView */
	PhaseView* phaseView; /** < Instance of a PhaseView */
	CardPlayedView* cardPlayedView; /** < Instance of a CardPlayedView */
	GameMap* map; /** < Game board */
	vector<Player*>* playerList; /** < List of players currently playing */
	Deck<GameCard*>* deckOfCards; /** < Deck of GameCards */
	int* turnOrder; /** < Turn order */
	DiceView* diceView; /** < Instance of a DiceView */
};
#endif
