#include "item.hpp"

#include <random>
#include <time.h>

Item::Item(int x, int y)
{
	xPos = x;
	yPos = y;

	isActivated = false;

	turnsLeftOnBoard = 3;
	turnsLeftActivated = -1;

	activatingUnit = PIECES::EMPTY;

	//TODO: load some desc from a file
	itemDesc = "";

	//randomly select which item to spawn
	std::srand((unsigned int)time(NULL));

	int r = std::rand() % 5;

	itemType = (ITEMS)r;
}

Item::~Item()
{
}

void Item::update()
{
	if (!isActivated)
	{
		turnsLeftOnBoard--;
	}
	else
	{
		turnsLeftActivated--;
	}
}
