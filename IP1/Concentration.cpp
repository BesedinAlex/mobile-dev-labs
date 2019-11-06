//---------------------------------------------------------------------------

#pragma hdrstop

#include "Concentration.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

Concentration::Concentration(int numberOfPairsOfCards)
{
	Concentration::pairsOfCards = numberOfPairsOfCards;
	Concentration::win = false;
	for (int i = 0; i < Concentration::pairsOfCards; i++)
	{
		Concentration::cards.push_back(*(new Card(i)));
		Concentration::cards.push_back(*(new Card(i)));
	}
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	auto rng = std::default_random_engine(seed);
	std::shuffle(Concentration::cards.begin(), Concentration::cards.end(), rng);
}

void Concentration::restart()
{
	Concentration::cards.clear();
	Concentration::win = false;
	for (int i = 0; i < Concentration::pairsOfCards; i++)
	{
		Concentration::cards.push_back(*(new Card(i)));
		Concentration::cards.push_back(*(new Card(i)));
	}
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	auto rng = std::default_random_engine(seed);
	std::shuffle(Concentration::cards.begin(), Concentration::cards.end(), rng);
}

void Concentration::chooseCard(int index)
{
    if (!Concentration::cards[index].isMatched)
	{
        int facedUpCardIndex = -1;
        int cardsFound = 0;
		for (int i = 0; i < Concentration::cards.size(); i++)
		{
            if (!Concentration::cards[i].isMatched && Concentration::cards[i].isFaceUp)
            {
                facedUpCardIndex = i;
                cardsFound += 1;
            }
        }
        if (cardsFound == 0 || cardsFound == 2)
        {
			for (int i = 0; i < Concentration::cards.size(); i++)
			{
				if (!Concentration::cards[i].isMatched) {
					Concentration::cards[i].isFaceUp = false;
				}
			}
            Concentration::cards[index].isFaceUp = true;
            return;
        }
        else
        {
            bool equals = Concentration::cards[index].identifier == Concentration::cards[facedUpCardIndex].identifier;
            Concentration::cards[index].isMatched = Concentration::cards[facedUpCardIndex].isMatched = equals;
			Concentration::cards[index].isFaceUp = Concentration::cards[facedUpCardIndex].isFaceUp = true;
			int matchedCards = 0;
			for (int i = 0; i < Concentration::cards.size(); i++)
			{
				matchedCards += Concentration::cards[i].isMatched ? 1 : 0;
			}
			Concentration::win = matchedCards == Concentration::pairsOfCards * 2;
        }
    }
}