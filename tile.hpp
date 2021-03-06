#pragma once

#include "pieces.hpp"
#include "items.hpp"
#include "color.hpp"

#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Tile
{
	private:

		//the width and length of a tile, must be at least 1 and must not be even
		//these borders are determined automatically
		static int size;

		//tells what the tile is occupied by
		PIECES occupied_by;

		//tells what item lays on the tile
		ITEMS houses;

		//tells what color the tile is
		COLOR color;

		//a representation of one tile
		vector<string> tile;

		//the default line of the tile
		string defaultLine;

		//updates the tile representation
		void updateTile();

	public:

		//empty constructor
		Tile();

		//constructs a new tile
		/*
		* parameters:
		* c: the color the tile will have
		* size: the width and length of a tile
		*/
		Tile(COLOR c, int size = 1);

		//destroys the tile
		~Tile();

		//returns the color of the tile
		const COLOR getColor() { return color; };

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

		//returns the visual representation of the tile
		vector<string> getTile() { return tile; };


#if (defined DEBUG) || (defined _DEBUG)
		//prints the tile on console
		//for debugging only
		void printTile();
#endif
};
