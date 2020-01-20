//---------------------------------------------------------------------------

#ifndef SquaresH
#define SquaresH

#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <chrono>

//---------------------------------------------------------------------------
#endif

struct Squares
{
    std::vector<int> squareColors;
    
	int rightAnswer;
    int compareState;

    Squares(int difficultLevel);

	void restart(int difficultLevel);

	void start(int difficultLevel);
};

/*

0 - blue
1 - yellow
2 - red
3 - green
4 - white

*/