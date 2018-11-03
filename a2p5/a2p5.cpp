#include <iostream>
#include "Player.h"
#include "GameMapLoader.h"

/**
 * Function used to aske a yes-no question.
 * @param question question being answered
 * @param positiveAnswer char representing a positive asnwer for the question
 * @param negativeAnswer char representing a negative answer for the question
 * @return true if answer with positiveAnswer, false if answered with a negativeAnswer
 */
bool askYesNoQuestion(string question, char positiveAnswer, char negativeAnswer) {
	char answer = -1;
	while (answer != positiveAnswer && answer != negativeAnswer) {
		cout << question << "(" << positiveAnswer << " or " << negativeAnswer << "):";
		cin >> answer;
	}
	return answer == positiveAnswer;
}

/**
 * Function used to asked a choice question.
 * @param question the question being asked
 * @param lowerChoice lower bound limit for choices

 */
int askChoiceQuestion(string question, int lowerChoice, int upperChoice) {
	int choice = -1;
	while (choice < lowerChoice || choice > upperChoice) {
		cout << question;
		cin >> choice;
	}
	return choice;
}


template <typename T> void printVector(vector<T> aVector) {
	typename vector<T>::iterator anIterator;
	for (anIterator = aVector.begin(); anIterator != aVector.end(); anIterator++) {
		cout << *anIterator << endl;
	}
}

void executeMovePhase(Player *player, GameMap *map) {
	vector<GameMapNode*> neighbours = map->getZoneByName(player->getCurrentZone())->getNeighbours();

	if (neighbours.size() == 0) {
		cout << "Since you are in Upper Manhatten you need to stay there." << endl;
		player->endPhase();
	} else if (neighbours.size() == 1) {
		cout << "Since you were in " << player->getCurrentZone() << " you were moved to " << neighbours.at(0)->getZoneName() << endl;
		player->move(map, neighbours.at(0)->getZoneName());
	} else {
		cout << "List of possible zones:" << endl;
		for (int i = 0; i<neighbours.size(); i++) {
			cout << (i + 1) << ")" << neighbours.at(i)->getZoneName() << endl;
		}
		int choice = askChoiceQuestion("Select which zone you want to move to? (0 to skip this phase)", 0, neighbours.size());
		if (choice != 0) {
			player->move(map, neighbours.at(choice - 1)->getZoneName());
		}
		else {
			player->endPhase();
		}
	}
}

int main()
{
	GameMap *map = GameMapLoader::loadMap("..\\king-of-new-york\\MapDirectory\\new_york.map");
	MonsterCard *monsterCard = new MonsterCard("Test", "Test");
	Player player(monsterCard, 0, "Bronx", PlayerStateMachine::PlayerState::Moving);
	cout << "Initial zone " << player.getCurrentZone() << endl;
	executeMovePhase(&player, map);
	cout << "End zone " << player.getCurrentZone() << endl;
	system("pause");
}
