//---------------------------------------------------------------------------

#pragma hdrstop

#include "Squares.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Squares::Squares(int difficultLevel)
{
    start(difficultLevel);
}

void Squares::restart(int difficultLevel)
{
    Squares::squareColors.clear();
    start(difficultLevel);
}

void Squares::start(int difficultLevel)
{
    int blue = 0;
    int yellow = 0;
    int red = 0;
	int green = 0;
    switch (difficultLevel)
    {
    case 0:
        blue = rand() % 12;
        yellow = rand() % 12;
        break;
    case 1:
        blue = rand() % 8;
        yellow = rand() % 8;
        red = rand() % 8;
        break;
    case 2:
        blue = rand() % 6;
        yellow = rand() % 6;
        red = rand() % 6;
        green = rand() % 6;
        break;
    }
    int colorSum = blue + yellow + red + green;
    while (colorSum >= 25)
    {
        blue /= 2;
        yellow /= 2;
        red /= 2;
        green /= 2;
        colorSum = blue + yellow + red + green;
    }
    for (int i = 0; i < blue; i++)
    {
        Squares::squareColors.push_back(0);
    }
    for (int i = 0; i < yellow; i++)
    {
        Squares::squareColors.push_back(1);
	}
	if (blue > yellow)
	{
		compareState = 0;
	}
	else if (blue == yellow)
	{
		compareState = 1;
	}
	else
	{
        compareState = 2;
    }
    for (int i = 0; i < red; i++)
    {
        Squares::squareColors.push_back(2);
    }
    for (int i = 0; i < green; i++)
    {
        Squares::squareColors.push_back(3);
    }
    Squares::rightAnswer = 25 - colorSum;
    for (int i = 0; i < Squares::rightAnswer; i++)
    {
        Squares::squareColors.push_back(4);
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	auto rng = std::default_random_engine(seed);
	std::shuffle(Squares::squareColors.begin(), Squares::squareColors.end(), rng);
}