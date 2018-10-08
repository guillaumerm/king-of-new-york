#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <ostream>

using namespace std;

template <class T> class Deck {
public:
	Deck(int);
	void shuffle();
	T* operator[](int);
	T* deal();
	int size();
	bool isEmpty() const;
	void push(T item);
private:
	int top;
	int currentSize;
	T* items;
};

#endif
