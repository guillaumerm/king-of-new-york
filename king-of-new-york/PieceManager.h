#pragma once
#include "Util.h"
#include "GameCard.h"
#include "DiscardCard.h"
#include "KeepCard.h"
#include "GoalCard.h"
#include "MonsterCard.h"
#include "EnergyCube.h"
#include "Token.h"
#include "Deck.h"
#include "DeckCard-impl.cpp"
#include "GainPointsDiscardCard.h"
#include "CostLessToBuyDiscardCard.h"
#include "AddToRollKeepCard.h"


using namespace std;

template <class T> void printDeck(Deck<T>* deck);

Token* initTokens(int numWeb, int numJinx, int numCara, int numSouv);

Deck<GameCard*>* initDeck(CardPlayedObserver *observer);

MonsterCard* initMonsterCards();