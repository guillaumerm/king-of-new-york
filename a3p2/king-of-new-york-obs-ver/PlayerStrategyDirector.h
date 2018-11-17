#ifndef PLAYER_STRATEGY_DIRECTOR_H
#define PLAYER_STRATEGY_DIRECTOR_H
#include "PlayerStrategyBuilder.h"

class PlayerStrategyDirector {
public:
	void setPlayerStrategyBuilder(PlayerStrategyBuilder* playerStrategyBuilder);
	PlayerStrategy*  getPlayerStrategy();
	void constructPlayerStrategy();
private:
	PlayerStrategyBuilder* playerStrategyBuilder;
};
#endif
