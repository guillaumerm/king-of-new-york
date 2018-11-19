#ifndef GAME_STATISTIC_INTERFACE_H
#define GAME_STATISTIC_INTERFACE_H

/**
 * @brief An interface that regroup console output functions used by concrete GameStatisticInterface
 */
class GameStatisticInterface{
public:
	/**
	 * Display the current information about the current GameStatistic.
	 */
	virtual void show() = 0;
};
#endif
