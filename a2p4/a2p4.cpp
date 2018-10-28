// a2p4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Player.h"
#include <iostream>
using namespace std;

/**
 * Function used to aske a yes-no question.
 * @param question question being answered
 * @param positiveAnswer char representing a positive asnwer for the question
 * @param negativeAnswer char representing a negative answer for the question
 * @return true if answer with positiveAnswer, false if answered with a negativeAnswer
 */
bool askYesNoQuestion(string question, char positiveAnswer, char negativeAnswer) {
	char answer = -1;
	while (answer != positiveAnswer && answer != negativeAnswer) {
		cout << question << "(" << positiveAnswer << " or " << negativeAnswer << "):";
		cin >> answer;
	}
	return answer == positiveAnswer;
}

/**
 * Function used to asked a choice question.
 * @param question the question being asked
 * @param lowerChoice lower bound limit for choices

 */
int askChoiceQuestion(string question, int lowerChoice, int upperChoice) {
	int choice = -1;
	while (choice < lowerChoice || choice > upperChoice) {
		cout << question;
		cin >> choice;
	}
	return choice;
}

/**
 * Function used to execute the roll dice phase
 * @param player player which is executing the roll dice phase
 * @param numberOfDice number of dice being rolled in this dice phase
 */
void executeRollDicePhase(Player &player, int numberOfDice) {
	bool *diceToKeep = new bool[numberOfDice];
	const DiceRoll *diceRoll = player.rollDice(numberOfDice);

	// While the player can roll/rerall continue this loop
	while (player.isRolling()) {
		cout << "You've rolled:" << *diceRoll << endl;

		// Asks if the player wants to reroll
		if (askYesNoQuestion("Do you want to reroll?", 'y', 'n')) {
			bool *diceToKeep = new bool[numberOfDice];

			// Dicide which dice to keep and which to roll.
			for (int i = 0; i < numberOfDice; i++) {
				diceToKeep[i] = askYesNoQuestion("Keep dice " + to_string(i + 1) + " which as symbol " + dieFaceToString(diceRoll->getFaceAt(i)), 'y', 'n');
			}

			diceRoll = player.rollDice(diceToKeep);
		}
		else {
			// End the rolling phase
			player.endPhase();
		}
	}
}

/**
 * Function used to execute the dice resolution phase
 * @param player player whic is executing the resolve dice phase
 */
void executeResolveDicePhase(Player &player) {
	// Decide the order in which the dice will be played.
	unordered_set<Die::Face> order;
	while (order.size() < 6) {
		int choice = askChoiceQuestion("Enter the symbol of the dice you want to resolve [A(0), C(1), D(2), E(3), H(4), O(5)]:", 0, 5);
		
		if (!order.emplace((Die::Face)choice).second) {
			cerr << "You have already decided for this symbol." << endl;
		}
	}
	// Given the order obtain the count for each Die::Face from the last roll of the player
	unordered_map<Die::Face, int> resolveDecision = player.resolveDice(order);
	unordered_map<Die::Face, int>::iterator iter;

	cout << "The order you decided to resolve the dice is the following" << endl;

	for (iter = resolveDecision.begin(); iter != resolveDecision.end(); iter++) {
		cout << iter->first << " => " << iter->second << endl;
	}
}

// TODO make function and add the reroll option
int main()
{
	Player player;
	player.startTurn();
	int numberOfDice = -1;
	cout << "Number of dice to roll:" << endl;
	cin >> numberOfDice;

	executeRollDicePhase(player, numberOfDice);
	executeResolveDicePhase(player);

	return 0;
}