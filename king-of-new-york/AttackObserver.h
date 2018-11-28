#ifndef ATTACK_OBSERVER_H
#define ATTACK_OBSERVER_H
#include <string>
class AttackObserver {
public:
	virtual void update(std::string playerName, bool attackManhatten, int attackAmount) = 0;
};
#endif