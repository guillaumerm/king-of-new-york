#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <ostream>

using namespace std;

/**
 * @brief Class deck includes different behavior that a deck of game components would require.
 * @author Guillaume Rochefort-Mathieu
 */
template <class T> class Deck {
public:
	/**
	 * A constructor that takes the max size as a parameter.
	 */
	Deck(int);

	/**
	 * A destructor that cleans the Deck object instance
	 */
	~Deck();

	/**
	 * Shuffles the element of the deck instance.
	 * This shuffle function uses an implementation of the modern algorithm of "Fisher–Yates shuffle".
	 */
	void shuffle();

	T* operator[](int);

	/**
	 * Deals the first item on top of the deck. Throws 
	 */
	T* deal();

	/**
	 * Get the size of the deck instance.
	 * @return int size of the deck instance
	 */
	int size();

	/**
	 * Check if the deck instance is empty
	 * @return true if empty, false otherwise
	 */
	bool isEmpty() const;

	/**
	 * Push the item on top of the deck.
	 * @param item a item top be pushed
	 * @throws exception if the deck is full
	 */
	void push(T item);
private:
	int top; /**< Top index of the deck */
	int currentSize; /**< Current size of the deck */
	int maxSize; /**< Maximum size of the deck */
	T* items; /**< Items currently stored in the deck */
};

#endif
