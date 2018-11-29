#include "Util.h"

/**
 *Function used to print a vector
 * @param aVector vector being printed
 */
template <typename T> inline void printVector(const std::vector<T> &aVector) {
	typename vector<T>::iterator anIterator;
	for (anIterator = aVector.begin(); anIterator != aVector.end(); anIterator++) {
		std::cout << *anIterator << std::endl;
	}
}

/**
 * Function used to print a set
 * @param aSet set being printed
 */
template <typename T> inline void printSet(const std::unordered_set<T> &aSet) {
	typename unordered_set<T>::iterator anIterator;
	for (anIterator = aSet.begin(); anIterator != aSet.end(); anIterator++) {
		std::cout << *anIterator << std::endl;
	}
}

/**
 * Function used to print an array
 * @param array array being printed
 * @param size size of the array
 */
template <typename T> inline void printArray(const T* array, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << std::endl;
	}
	std::cout << std::endl;
}

/**
 * Function used to aske a yes-no question.
 * @param question question being answered
 * @param positiveAnswer char representing a positive asnwer for the question
 * @param negativeAnswer char representing a negative answer for the question
 * @return true if answer with positiveAnswer, false if answered with a negativeAnswer
 */
bool askYesNoQuestion(std::string question, char positiveAnswer, char negativeAnswer) {
	char answer = -1;
	while (answer != positiveAnswer && answer != negativeAnswer) {
		std::cout << question << "(" << positiveAnswer << " or " << negativeAnswer << "):";
		std::cin >> answer;
	}
	return answer == positiveAnswer;
}

/**
 * Function used to asked a choice question.
 * @param question the question being asked
 * @param lowerChoice lower bound limit for choices

 */
int askChoiceQuestion(std::string question, int lowerChoice, int upperChoice) {
	int choice = -2;
	while (choice < lowerChoice || choice > upperChoice) {
		std::cout << question;
		std::cin >> choice;
	}
	return choice;
}