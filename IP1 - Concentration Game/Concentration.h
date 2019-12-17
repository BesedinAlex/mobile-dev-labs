//---------------------------------------------------------------------------

#ifndef ConcentrationH
#define ConcentrationH

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "Card.h"

//---------------------------------------------------------------------------
#endif

struct Concentration
{
	std::vector<Card> cards;

	bool win;
    int pairsOfCards;
	
	Concentration(int numberOfPairsOfCards);

	void chooseCard(int index);

    void restart();
};