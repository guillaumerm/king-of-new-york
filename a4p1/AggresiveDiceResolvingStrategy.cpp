#include "AggresiveDiceResolvingStrategy.h"

void AggresiveDiceResolvingStrategy::execute(Player &player) {
	// Sets the order to a predefined aggresive order.
	Die::Face aggresiveOrder[] = { Die::Face::A, Die::Face::D, Die::Face::H, Die::Face::E, Die::Face::C, Die::Face::O };
	unordered_set<Die::Face> order (aggresiveOrder, aggresiveOrder + 6);

	// Given the order obtain the count for each Die::Face from the last roll of the player
	unordered_map<Die::Face, int> resolveDecision = player.resolveDice(order);

	player.endPhase();
}