#ifndef DECK_H
#define DECK_H
#include <iostream>

using namespace std;

template <class T> class Deck {
public:
	Deck(T**, int);
	void shuffle();
	T* deal();
	int size();
	bool isEmpty() const;
	void setItems(T**, int);
private:
	friend ostream& operator<<(ostream&, const Deck<T>&);
	int top;
	int currentSize;
	T** items;
};

#endif
