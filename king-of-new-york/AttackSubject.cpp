#include "AttackSubject.h"

AttackSubject::AttackSubject()
{
	this->observers = new std::list<AttackObserver*>();
}

void AttackSubject::attach(AttackObserver * ob)
{
	this->observers->push_back(ob);
}

void AttackSubject::detach(AttackObserver * ob)
{
	this->observers->remove(ob);
}

void AttackSubject::notify(std::string playerName, bool attackManhatten, int attackAmount)
{
	for (auto oberser : *this->observers) {
		oberser->update(playerName, attackManhatten, attackAmount);
	}
}

AttackSubject::~AttackSubject()
{
	delete this->observers;
}
