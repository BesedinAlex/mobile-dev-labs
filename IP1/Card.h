//---------------------------------------------------------------------------

#ifndef CardH
#define CardH
//---------------------------------------------------------------------------
#endif

struct Card
{
	static int numberOfCards;

	int identifier;
	bool isFaceUp;
	bool isMatched;

	Card();

	static int getUniqueIdentifier();
};