#include "InteractiveDiceResolvingStrategy.h"
#include "Util.h"

void InteractiveDiceResolvingStrategy::execute(Player & player) {
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

	/*cout << "The order you decided to resolve the dice is the following" << endl;

	for (iter = resolveDecision.begin(); iter != resolveDecision.end(); iter++) {
		cout << iter->first << " => " << iter->second << endl;
	}*/

	player.endPhase();
}
