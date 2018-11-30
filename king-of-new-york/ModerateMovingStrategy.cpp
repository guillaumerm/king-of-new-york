#include "ModerateMovingStrategy.h"

void ModerateMovingStrategy::execute(Player * player, GameMap * map) {
	if (map->getPlayersCountInManhantten() < 1) {
		player->move(map, "Lower Manhatten");
	}
	else {
		// Obtain the possible valid moves from current zone of the player
		vector<GameMapNode*> possibleMoves = map->getZoneByName(player->getCurrentZone())->getNeighbours();

		// Player is currenty in Manhantten and needs to proceed a level higer
		if (possibleMoves.size() == 1) {
			player->move(map, possibleMoves.at(0)->getZoneName());
		}
		else {
			player->endPhase();
		}
	}

	player->endPhase();
}
