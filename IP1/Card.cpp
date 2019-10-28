//---------------------------------------------------------------------------

#pragma hdrstop

#include "Card.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Card::Card(int index)
{
	Card::identifier = index;
	Card::isFaceUp = false;
	Card::isMatched = false;
}
