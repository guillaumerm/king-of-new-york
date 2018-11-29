#include "Die.h"

using namespace std;

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

string dieFaceToString(Die::Face face)
{
	switch (face) {
	case Die::Face::A:
		return "A";
		break;
	case Die::Face::C:
		return "C";
		break;
	case Die::Face::D:
		return "D";
		break;
	case Die::Face::E:
		return "E";
		break;
	case Die::Face::H:
		return "H";
		break;
	case Die::Face::O:
		return "O";
		break;
	default:
		throw new out_of_range("Not a valid Die::Face");
		exit(1);
	}
}

ostream& operator<<(ostream& strm, const Die::Face face) {
	strm << dieFaceToString(face);
	return strm;
}
