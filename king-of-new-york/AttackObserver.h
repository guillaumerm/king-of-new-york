#ifndef ATTACK_OBSERVER_H
#define ATTACK_OBSERVER_H
#include <string>

/**
 * @brief Observer used to subscribe to AttackSubject. That is it will get notify when an AttackSubject attacks.
 */
class AttackObserver {
public:
	/**
	 * Handle the attack notification from the AttackSubject. Attack all players that fits the description that is not the attacking player and whether the attack is targeted towards Manhatten or not.
	 * @param playerName Name of the player attacking
	 * @param attackManhatten Targetting player in Manhatten
	 * @param attackAmount Amount to be removed for players
	 */
	virtual void update(std::string playerName, bool attackManhatten, int attackAmount) = 0;
};
#endif