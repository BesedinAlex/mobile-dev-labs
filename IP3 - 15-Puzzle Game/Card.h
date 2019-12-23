//---------------------------------------------------------------------------

#ifndef CardH
#define CardH
//---------------------------------------------------------------------------
struct Card
{
	int id;
	int size;

	bool pathToNorth;
	bool pathToEast;
	bool pathToSouth;
	bool pathToWest;

	Card(int size);

	void move(int directionId);
}
#endif
