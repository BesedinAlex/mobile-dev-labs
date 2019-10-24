//---------------------------------------------------------------------------

#pragma hdrstop

#include "Card.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int Card::numberOfCards = 0;

Card::Card()
{
	Card::identifier = Card::getUniqueIdentifier();
	Card::isFaceUp = false;
	Card::isMatched = false;
}

int Card::getUniqueIdentifier()
{
	Card::numberOfCards += 1;
	return Card::numberOfCards;
}

bool Card::equals(Card a, Card b)
{
	return a.identifier == b.identifier;
}
