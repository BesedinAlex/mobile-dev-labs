//---------------------------------------------------------------------------

#ifndef ConcentrationH
#define ConcentrationH

#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"

//---------------------------------------------------------------------------
#endif

struct Concentration
{
	std::vector<Card> cards;
	
	Concentration(int numberOfPairsOfCards);

	void chooseCard(int index);
	
};