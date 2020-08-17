#pragma once

#include "pieces.hpp"
#include "items.hpp"
#include <vector>

class Tile
{
	private:

		//the width and length of a tile, must be at least 1
		static int size;

		//tells what the tile is occupied by
		PIECES occupied_by;

		//tells what item lays on the tile
		ITEMS houses;

		//a representation of one tile
		std::vector<char> tile;

		//updates the tile representation
		void updateTile();

	public:

		//returns the width or length of one tile
		static int getSize();

		//tells what type of piece the tile is occupied by
		PIECES occupiedBy() { return occupied_by; };

		//sets what unit occupies the tile
		void occupie(PIECES unit) { occupied_by = unit; updateTile(); };

		//tells what item lays on the tile
		ITEMS housing() { return houses; };

		//sets an item on this tile
		void house(ITEMS item) { houses = item; updateTile(); };

		std::vector<char> getTile() { return tile; };
};
