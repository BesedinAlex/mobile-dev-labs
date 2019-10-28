//---------------------------------------------------------------------------

#pragma hdrstop

#include "Concentration.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

Concentration::Concentration(int numberOfPairsOfCards)
{
    for (int i = 0; i < numberOfPairsOfCards; i++)
    {
        auto card = new Card();
		Concentration::cards.push_back(*card);
        Concentration::cards.push_back(*card);
    }
    std::vector<Card> tempCards;
	for (int i = 0; Concentration::cards.size; i++)
	{
		int randomIndex = std::rand();
        auto card = Concentration::cards[randomIndex];
		Concentration::cards.erase(Concentration::cards.begin() + randomIndex);
		tempCards.push_back(card);
	}
    Concentration::cards = tempCards;
}

void Concentration::chooseCard(int index)
{
    if (!Concentration::cards[index].isMatched)
    {
        int facedUpCardIndex = -1;
        for (int i = 0; i < Concentration::cards.length; i++)
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