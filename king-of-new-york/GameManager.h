#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "Player.h"
#include "GameStatisticView.h"
#include "CardPlayedView.h"
#include "DiceView.h"
#include "PhaseView.h"
#include "GameMapLoader.h"
#include "PieceManager.h"
#include "PlayerStrategyDirector.h"
#include "ModeratePlayerStrategyBuilder.h"
#include "AggresivePlayerStrategyBuilder.h"
#include "InteractivePlayerStrategyBuilder.h"
#include "Util.h"

using namespace std;

/**
 * @brief Main controller from controlling the view and the models.
 */
class GameManager: public AttackObserver {
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

	void update(string playerName, bool attackManhatten, int attackAmount);

	/**
	 * Initiates the main game loop.
	 */
	void play();
private:
	vector<GameCard*>* cardsAvailable; /** < GameCards available to buy */
	Player* currentPlayer; /** < Player who is currently playing */
	GameStatisticView* statisticView; /** < Instance of a GameStatisticView */
	PhaseView* phaseView; /** < Instance of a PhaseView */
	DiceView* diceView;
	CardPlayedView* cardPlayedView; /** < Instance of a CardPlayedView */
	GameMap* map; /** < Game board */
	vector<Player*>* playerList; /** < List of players currently playing */
	Deck<GameCard*>* deckOfCards; /** < Deck of GameCards */
	int* turnOrder; /** < Turn order */
};
#endif
