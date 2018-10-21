// a2p4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Player.h"
#include <iostream>
using namespace std;

// TODO make function and add the reroll option
int main()
{
	Player player;
	int numberOfDice = -1;
	cout << "Number of dice to roll:" << endl;
	cin >> numberOfDice;
	bool *diceToKeep = new bool[numberOfDice];
	cout << "You've rolled:" << *player.rollDice(diceToKeep, numberOfDice) << endl;
	unordered_set<Die::Face> order;
	while (order.size() < 6) {
		int symbol = 0;
		cout << "Enter the symbol of the dice you want to resolve [A(0), C(1), D(2), E(3), H(4), O(5)]:" << endl;
		cin >> symbol;
		if (symbol <= 0 && symbol >= 5) {
			cerr << "You must enter a symbol between A(0) and O(5)" << endl;
		}
		else if (!order.emplace((Die::Face)symbol).second) {
			cerr << "You have already decided for this symbol." << endl;
		}
	}

	unordered_map<Die::Face, int> resolveDecision = player.resolveDice(order);
	unordered_map<Die::Face, int>::iterator iter;
	
	cout << "The order you decided to resolve the dice is the following" << endl;

	for (iter = resolveDecision.begin(); iter != resolveDecision.end(); iter++) {
		cout << iter->first << " => " << iter->second << endl;
	}

	return 0;
}