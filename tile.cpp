#include "tile.hpp"

int Tile::size;

void Tile::updateTile()
{
	//the char holding the new representation letter
	char representationLetter = '#';

	//check for the piece
	if (occupied_by != EMPTY)
	{
		switch (occupied_by)
		{
			case KING:
			{
				representationLetter = 'K';
			}break;
			case QUEEN:
			{
				representationLetter = 'Q';
			}break;
			case ROOK:
			{
				representationLetter = 'R';
			}break;
			case KNIGHT:
			{
				representationLetter = 'N';
			}break;
			case BISHOP:
			{
				representationLetter = 'B';
			}break;
			case PAWN:
			{
				representationLetter = 'P';
			}break;
		}
	}
	
	//check for the item
	if (houses != NOTHING)
	{
		switch (houses)
		{
			case MIRROR:
			{
				representationLetter = 'M';
			}break;
			case POISON:
			{
				representationLetter = 'O';
			}break;
		}
	}

	//calculate the position in the string where the char must be altered
	int i = (((size / 2) + 1) * (size + 1)) - ((size / 2) + 1);

	//change the char at i
	tile.replace(tile.begin() + i - 1, tile.end() - i, 1, representationLetter);

}

Tile::Tile(COLOR c, int size)
{
	//initialize members
	if (size < 1)
		size = 1;
	else if (size % 2 == 0)
		size++;

	this->size = size;
	occupied_by = PIECES::EMPTY;
	houses = ITEMS::NOTHING;
	color = c;

	//initialize representation
	switch (color)
	{
		case BLACK:
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					tile.push_back('#');
				}

				tile.push_back('\n');
			}
		}
		case WHITE:
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					tile.push_back('_');
				}

				tile.push_back('\n');
			}
		}
	}
}

Tile::~Tile()
{

}

int Tile::getSize()
{
	return size;
}

void Tile::printTile()
{
	std::cout << tile << std::endl;
}

