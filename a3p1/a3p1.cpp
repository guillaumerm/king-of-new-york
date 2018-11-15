#include <iostream>
#include "Player.h"
#include "PlayerStrategyDirector.h"
#include "ModeratePlayerStrategyBuilder.h"
#include "InteractivePlayerStrategyBuilder.h"
#include "AggresivePlayerStrategyBuilder.h"
#include "Deck.h"
#include "GameManager.h"
#include "DeckCard-impl.cpp"

/**
 * Verifies if any of the player has won.
 * @param playerList the playerList
 * @return winning player, otherwise NULL
 */
Player *hasWon(vector<Player *>* playerList) {
	vector<Player *>::iterator curPlayer;
	int dead = 0;
	Player * lastALife = NULL;
	for (curPlayer = playerList->begin(); curPlayer != playerList->end(); curPlayer++) {
		if ((*curPlayer)->isDead()) {
			dead++;
		}
		else if ((*curPlayer)->getVictoryPoints() == 20) {
			return *curPlayer;
		}
		else {
			lastALife = *curPlayer;
		}
	}

	if (dead == playerList->size() - 1) {
		return lastALife;
	}

	return NULL;
}

int main() {
	PlayerStrategyDirector playerPlayerStrategyDirector;
	PlayerStrategyBuilder* moderatePlayerStrategyBuilder = new ModeratePlayerStrategyBuilder;
	PlayerStrategyBuilder* aggresivePlayerStrategyBuilder = new AggresivePlayerStrategyBuilder;
	PlayerStrategyBuilder* interactivePlayerStrategyBuilder = new InteractivePlayerStrategyBuilder;
	playerPlayerStrategyDirector.setPlayerStrategyBuilder(moderatePlayerStrategyBuilder);
	playerPlayerStrategyDirector.constructPlayerStrategy();

	cout << "Welcome to the King of New York game!" << endl;
	cout << "This driver will set up the New York map and create a game for 4 players." << endl;
	cout << endl << endl << "[1] Start Phase" << endl << endl << endl;

	GameMap* map = new GameMap();
	vector<Player*>* playerList = new vector<Player*>();
	Deck<GameCard*>* deckOfCards = new Deck<GameCard*>(64);
	executeStart(*map, *playerList, *deckOfCards);
	
	for(auto iter: *playerList) {
		playerPlayerStrategyDirector.constructPlayerStrategy();
		iter->setPlayerStrategy(playerPlayerStrategyDirector.getPlayerStrategy());
	}

	vector<GameCard*> cardsAvailable;
	cardsAvailable.push_back(*deckOfCards->deal());
	cardsAvailable.push_back(*deckOfCards->deal());
	cardsAvailable.push_back(*deckOfCards->deal());

	cout << endl << endl << "[2] Start Up Phase" << endl << endl << endl;

	int *turnOrder = executeStartupPhase(map, playerList);

	cout << endl << endl << "[3] Main Game Loop" << endl << endl << endl;

	Player* winningPlayer;
	// Main game loop - play until someone wins
	while (!(winningPlayer = hasWon(playerList))) {
		for (int turn = 0; turn < playerList->size(); turn++) {
			cout << "--Player " << turnOrder[turn] << " turn--" << endl;
			Player* curPlayer = playerList->at(turnOrder[turn]);

			// Precondition of playing a turn the player must not be dead
			if (curPlayer->isDead()) {
				continue;
			}
			curPlayer->startTurn();

			curPlayer->executeTurn(map, cardsAvailable, 6);

			curPlayer->endTurn();
		}
		// Line to accelerate to the winning condition
		playerList->at(0)->addVictoryPoints(20);
	}

	cout << winningPlayer->getMonster() << " has won the game" << endl;
	return 0;
}