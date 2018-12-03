#ifndef ATTACK_SUBJECT_H
#define ATTACK_SUBJECT_H
#include <list>
#include "AttackObserver.h"

/**
 * @brief AttackSubject as Subject that have the possibility of Attacking.
 */
class AttackSubject {
public:
	AttackSubject();
	virtual void attach(AttackObserver *ob);
	virtual void detach(AttackObserver *ob);
	virtual void notify(std::string playerName, bool attackManhatten, int attackAmount);
	~AttackSubject();
private:
	std::list<AttackObserver*> *observers;
};
#endif