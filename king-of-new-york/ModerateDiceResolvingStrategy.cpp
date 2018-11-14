#include "ModerateDiceResolvingStrategy.h"

void ModerateDiceResolvingStrategy::execute(Player & player) {
	// Sets the order to a predefined moderate order.
	Die::Face moderateOrder[] = { Die::Face::E, Die::Face::H, Die::Face::C, Die::Face::A, Die::Face::D, Die::Face::O };
	unordered_set<Die::Face> order(moderateOrder, moderateOrder + 6);

	// Given the order obtain the count for each Die::Face from the last roll of the player
	unordered_map<Die::Face, int> resolveDecision = player.resolveDice(order);

	player.endPhase();
}
