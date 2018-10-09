#include <cstdlib>
#include <string>
#include "Deck.h"

using namespace std;

template <class T> Deck<T>::Deck(int pSize) {
	this->items = new T[pSize];
	this->top = -1;
	this->currentSize = 0;
	this->maxSize = pSize;
};

template <class T> bool Deck<T>::isEmpty() const {
	return this->currentSize == 0;
}

template <class T> T* Deck<T>::deal(){
	
	if (!this->isEmpty()) {
		T* const top = &this->items[this->top];
		this->top -= 1;
		this->currentSize -= 1;
		return top;
	}
	else 
	{
		throw out_of_range("Deck is empty");
	}
}

template <class T> void Deck<T>::push(T item) {
	if (this->currentSize == this->maxSize) {
		throw exception("Deck is full");
	}

	this->items[++this->top] = item;
	this->currentSize++;
}

template <class T> int Deck<T>::size() {
	return this->currentSize;
}

/**
	Methods which shuffles the deck of card. The algorithm used to shuffle the cards is an implementation of the modern algorithm of "Fisher–Yates shuffle".
*/
template <class T> void Deck<T>::shuffle() {
	for (int sourceIndex = 0; sourceIndex < this->currentSize - 1; sourceIndex++) {
		int destinationIndex = rand() % (this->currentSize-1-sourceIndex) + sourceIndex;
		T source = this->items[sourceIndex];
		this->items[sourceIndex] = this->items[destinationIndex];
		this->items[destinationIndex] = source;
	}
}

template <class T> T* Deck<T>::operator[](int index)
{
	return &this->items[index];
}
