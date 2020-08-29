#include "tile.hpp"

int Tile::size;

void Tile::updateTile()
{
	//the char holding the new representation letter
	char representationLetter = (color == COLOR::BLACK) ? '#' : '~';

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

	//build the new middle line
	string midLine = "";

	for (int i = 0; i < size; i++)
	{
		if (i == (size - 1) / 2)
		{
			//this is the new representationLetter
			midLine.push_back(representationLetter);
		}
		else
		{
			//otherwise, just push back the default tile color
			midLine.push_back((color == COLOR::BLACK) ? '#' : '~');
		}
	}

	//build the updated tile
	tile.clear();

	for (int i = 0; i < size; i++)
	{
		if (i == (size - 1) / 2)
		{
			//the middle line has to be the updated one
			tile.push_back(midLine);
		}
		else
		{
			//every other line is just the default one
			tile.push_back(defaultLine);
		}
	}
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
			//build default line
			for (int i = 0; i < size; i++)
			{
				defaultLine.push_back('#');
			}

			//build the tile
			for (int i = 0; i < size; i++)
			{
				tile.push_back(defaultLine);
			}
		}
		case WHITE:
		{
			//build default line
			for (int i = 0; i < size; i++)
			{
				defaultLine.push_back('~');
			}

			//build the tile
			for (int i = 0; i < size; i++)
			{
				tile.push_back(defaultLine);
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

#if (defined DEBUG) || (defined _DEBUG)
void Tile::printTile()
{
	//build the tile string
	string res = "";

	for (int i = 0; i < size; i++)
	{
		res += tile.at(i);
		res += '\n';
	}

	//print the tile string
	cout << res << endl;
}
#endif

