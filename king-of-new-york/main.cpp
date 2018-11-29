#include "Util.cpp"
#include "GameManager.h"

int main() {
	GameManager *manager = new GameManager();
	manager->play();
	delete manager;
	return 0;
}