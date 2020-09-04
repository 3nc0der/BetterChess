#pragma once

#include "tile.hpp"
#include "singleton.hpp"
#include "logfile.hpp"

#define BOARD Board::get()

class Board : public singleton<Board>
{
	private:

		//two dimensional array of the board
		Tile board[8][8];

	public:

		//creates a new board
		//this is done automatically by the singleton class, the first time an instance of board is needed
		Board();

		//destroys the board
		~Board();

		//draws the board
		void drawBoard();

		//updates the board
		void updateBoard();
};
