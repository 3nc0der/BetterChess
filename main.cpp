#include "tile.hpp"

int main()
{
	Tile* t = new Tile(COLOR::WHITE, 3);
	t->printTile();

	t->occupie(QUEEN);
	t->printTile();

	return 0;
}