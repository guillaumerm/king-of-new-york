#include "Die.h"
#include <stdlib.h>
#include <time.h>


Die::Die() {
	this->roll();
}

Die::Face Die::roll() {
	/* initialize random seed: */
	/* Can be commented for testing purposes*/
	srand(time(NULL));

	/* randomly selecting a new face*/
	this->lastRoll = (Face)(rand() % 5 + 0);

	return this->lastRoll;
}

Die::Face Die::getLastRoll() const {
	return this->lastRoll;
}