#include "board.hpp"
#include "color.hpp"

Board::Board()
{
	COLOR c = COLOR::W;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = Tile(c, 3);
			c = (c == COLOR::B) ? COLOR::W : COLOR::B;
		}

		c = (c == COLOR::B) ? COLOR::W : COLOR::B;
	}
}

Board::~Board()
{
}

void Board::drawBoard()
{
	LOG->mf_writeToLog("Drawing board.", CYAN);

	string res = "";

	//build border line
	string border = "|";

	for (int i = 0; i < (Tile::getSize() * 8) + 7; i++)
	{
		border += "-";
	}

	border += "|\n";

	//go through all tile lines
	for (int i = 0; i < 8; i++)
	{
		//insert border
		res += border;

		//go through every tiles lines
		for (int j = 0; j < Tile::getSize(); j++)
		{
			//insert border
			res += '|';

			//go through all tiles in one line
			for (int k = 0; k < 8; k++)
			{
				res += board[i][k].getTile().at(j);
				
				//insert border
				res += '|';
			}

			//insert line end
			res += '\n';
		}
	}

	//insert the last border
	res += border;

	//print out the board
	cout << res << endl;
}

void Board::updateBoard()
{
}
