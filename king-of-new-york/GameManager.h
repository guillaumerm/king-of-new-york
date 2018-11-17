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

using namespace std;

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

	Player *hasWon();

	void play();
private:
	vector<GameCard*> cardsAvailable;
	Player* currentPlayer;
	GameStatisticView* statisticView;
	PhaseView* phaseView;
	GameMap* map;
	vector<Player*>* playerList;
	Deck<GameCard*>* deckOfCards;
	int* turnOrder;
};
#endif
