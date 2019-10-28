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
	std::vector<Card> tempCards;
	for (int i = 0; i < Concentration::cards.size(); i++)
	{
		int randomIndex = std::rand() % Concentration::cards.size();
		Card card = Concentration::cards[randomIndex];
		tempCards.push_back(card);
		Concentration::cards.erase(Concentration::cards.begin() + randomIndex);
	}
//	Concentration::cards = tempCards;
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