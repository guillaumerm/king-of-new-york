#include <cstdlib>
#include <string>
#include "Deck.h"

using namespace std;

template <class T> Deck<T>::Deck(T** cards, int pSize) {
	this->items = cards;
	this->top = pSize - 1;
	this->currentSize = pSize;
};

template <class T> bool Deck<T>::isEmpty() const {
	return this->currentSize != 0;
}

template <class T> T* Deck<T>::deal(){
	
	if (!this->isEmpty()) {
		T* const top = this->items[this->top];
		this->items[this->top] = NULL;
		this->top -= 1;
		this->currentSize -= 1;
		return top;
	}
	else 
	{
		throw new range_error("The deck is empty!");
	}
}

template <class T> int Deck<T>::size() {
	return this->currentSize;
}

template <class T> T* Deck<T>::get(int i) {
	return this->items[i];
}

template <class T> void Deck<T>::setItems(T** items, int size) {
	if (!this->isEmpty()) {
		for (int i = 0; i < this->currentSize; i++) {
			delete this->items[i];
			this->items[i] = NULL;
		}
	}
	delete this->items;
	this->items = items;
	this->top = size - 1;
	this->currentSize = size;
}

/**
	Methods which shuffles the deck of card. The algorithm used to shuffle the cards is an implementation of the modern algorithm of "Fisher–Yates shuffle".
*/
template <class T> void Deck<T>::shuffle() {
	for (int sourceIndex = 0; sourceIndex < this->currentSize - 1; sourceIndex++) {
		int destinationIndex = rand() % (this->currentSize-1-sourceIndex) + sourceIndex;
		T* source = this->items[sourceIndex];
		this->items[sourceIndex] = this->items[destinationIndex];
		this->items[destinationIndex] = source;
	}
}