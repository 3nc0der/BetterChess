#pragma once

#include "pieces.hpp"
#include "items.hpp"

class Piece
{
	public:

		//creates a new empty piece
		Piece(PIECES type, int x, int y);

		//destroys this piece
		~Piece();

		//pure virtual move method
		virtual void move() = 0;

		//this method is automatically called, when this piece moves on the field of an enemy unit
		void attack(Piece* attackedUnit);

		//this method is automatically called, when this piece moves over an item
		void collect(ITEMS collected);

		//getter & setter

		ITEMS getPossesedItem() { return possesedItem; };

		bool isAlive() { return is_alive; };

		PIECES getPieceType() { return pieceType; };

		int* getPosition() { int a[2] = { xPos, yPos }; return a; };

	private:

		//tells what type of piece this piece is
		PIECES pieceType;

		//tells what kind of item this unit is carrying if it does so
		ITEMS possesedItem;

		//where the unit is on the board
		int xPos, yPos;

		//tells if the piece is still in game or if it got slain
		bool is_alive;
};
