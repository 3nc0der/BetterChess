#pragma once

#include "pieces.hpp"
#include "items.hpp"

class Piece
{
	public:

		//creates a new empty piece
		Piece();

		//destroys this piece
		~Piece();

		//pure virtual move method
		virtual void move() = 0;

		//checks what units this piece is currently attacking
		virtual Piece* getAttackedPieces();

		//checks by what pieces this piece is currently being attacked
		virtual Piece* getAttackingPieces();

	private:

		//tells what type of piece this piece is
		PIECES pieceType;

		//tells what kind of item this unit is carrying if it does so
		ITEMS possesedItem;

		//where the unit is on the board
		int xPos, yPos;
};
