//---------------------------------------------------------------------------

#pragma hdrstop

#include "Concentration.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

Concentration::Concentration(int numberOfPairsOfCards)
{
	for (int i = 0; i < numberOfPairsOfCards; i++)
	{
		Concentration::cards.push_back(*(new Card(i)));
		Concentration::cards.push_back(*(new Card(i)));
	}
	auto rng = std::default_random_engine {};
	std::shuffle(Concentration::cards.begin(), Concentration::cards.end(), rng);
}

void Concentration::chooseCard(int index)
{
    if (!Concentration::cards[index].isMatched)
	{
        int facedUpCardIndex = -1;
		for (int i = 0; i < Concentration::cards.size(); i++)
		{
            if (!Concentration::cards[i].isMatched && Concentration::cards[i].isFaceUp)
            {
                facedUpCardIndex = i;
                break;
            }
        }
        if (facedUpCardIndex == -1)
        {
            Concentration::cards[index].isFaceUp = true;
            return;
        }
        else
        {
            bool equals = Concentration::cards[index].identifier == Concentration::cards[facedUpCardIndex].identifier;
            Concentration::cards[index].isMatched = Concentration::cards[facedUpCardIndex].isMatched = equals;
            Concentration::cards[index].isFaceUp = Concentration::cards[facedUpCardIndex].isFaceUp = equals;
        }
    }
}