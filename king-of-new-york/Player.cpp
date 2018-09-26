#include <string>
#include "Player.h"

using namespace std;

Player::Player(MonsterCard* monsterCard, int energyCubes) {
	this->monsterCard = monsterCard;
	this->energyCubes = energyCubes;
}

