#include "Die.h"
#include <stdlib.h>
#include <time.h>


Die::Die() {
	this->roll();
}

Die::Face Die::roll() {
	/* randomly selecting a new face*/
	this->lastRoll = (Face)(rand() % 6 + 0);

	return this->lastRoll;
}

Die::Face Die::getLastRoll() const {
	return this->lastRoll;
}