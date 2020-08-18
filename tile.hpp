#pragma once

#include "pieces.hpp"
#include "items.hpp"
#include "color.hpp"

#include <string.h>
#include <iostream>
#include <stdio.h>

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
		std::string tile;

		//updates the tile representation
		void updateTile();

	public:

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
		std::string getTile() { return tile; };

		//prints the tile on console
		//for debugging only
		void printTile();
};
