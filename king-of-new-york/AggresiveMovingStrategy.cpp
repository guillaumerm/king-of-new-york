#include "AggresiveMovingStrategy.h"

void AggresiveMovingStrategy::execute(Player *player, GameMap *map) {
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
		else if (player->getCurrentZone() != "Upper Manhatten") {
			

			// Checks if player is in Upper Manhatten or find first possible valid moves that is not in Manhatten since there is already a player
			bool possiblyInUpperManhatten = true;
			GameMapNode* possibleMove = NULL;


			for (auto move : possibleMoves) {
				possibleMove = move;
				possiblyInUpperManhatten &= possibleMove->isStartZone();
			}

			// Move to the newly found possible move if not in Manhatten
			if (!possiblyInUpperManhatten && possibleMove) {
				player->move(map, possibleMove->getZoneName());
			}
		}
	}

	player->endPhase();
}