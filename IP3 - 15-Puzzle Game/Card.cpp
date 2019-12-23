//---------------------------------------------------------------------------

#pragma hdrstop

#include "Card.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Card::Card(int size)
{
	Card::id = size * size;
	Card::size = size;
	Card::pathToNorth = true;
	Card::pathToEast = false;
	Card::pathToSouth = false;
    Card::pathToWest = true;
}

Card::move(int directionId)
{
	switch (directionId) {
	case 0: // North
		if (!Card::pathToNorth) {
			return;
		}
		Card::id -= Card::size;
		Card::pathToNorth = Card::id - Card::size > 0;
		Card::pathToSouth = true;
		break;
	case 1: // East
		if (!Card::pathToEast) {
			return;
		}
		Card::pathToEast = Card::id % Card::size != 0;
		Card::pathToWest = true;
		break;
	case 2: // South
		if (!Card::pathToSouth) {
			return;
		}
		Card::pathToSouth = Card::id + Card::size <= Card::size * Card::size;
		Card::pathToNorth = true;
		break;
	case 3: // West
		if (!Card::pathToWest) {
			return;
		}
		Card::pathToWest = (Card::id - 1) % Card::size != 0;
		Card::pathToEast = true;
		break;
	}
}