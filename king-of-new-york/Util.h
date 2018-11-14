#ifndef UTIL_H
#define UTIL_H
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 *Function used to print a vector
 * @param aVector vector being printed
 */
template <typename T> void printVector(const vector<T> &aVector);

/**
 * Function used to print a set
 * @param aSet set being printed
 */
template <typename T> void printSet(const unordered_set<T> &aSet);

/**
 * Function used to print an array
 * @param array array being printed
 * @param size size of the array
 */
template <typename T> void printArray(const T* array, int size);

/**
 * Function used to aske a yes-no question.
 * @param question question being answered
 * @param positiveAnswer char representing a positive asnwer for the question
 * @param negativeAnswer char representing a negative answer for the question
 * @return true if answer with positiveAnswer, false if answered with a negativeAnswer
 */
bool askYesNoQuestion(std::string question, char positiveAnswer, char negativeAnswer);

/**
 * Function used to asked a choice question.
 * @param question the question being asked
 * @param lowerChoice lower bound limit for choices

 */
int askChoiceQuestion(std::string question, int lowerChoice, int upperChoice);
#endif
