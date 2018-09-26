#ifndef GAME_PIECE_H
#define GAME_PIECE_H
#include <string>
using namespace std;

class GamePiece {
public:
	string getName();
	string getDescription();
private:
	string name;
	string description;
};
#endif
