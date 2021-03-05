#include "piece.hpp"

Piece::Piece(PIECES type, int x, int y)
{
	possesedItem = NOTHING;
	pieceType = type;
	xPos = x; yPos = y;
	is_alive = true;
}

Piece::~Piece()
{
	xPos = -1; yPos = -1;
	is_alive = false;
	pieceType = EMPTY;
	possesedItem = NOTHING;
}

void Piece::attack(Piece* attackedUnit)
{
	if (possesedItem == ITEMS::NOTHING)
	{
		possesedItem = attackedUnit->getPossesedItem();
	}

	attackedUnit->is_alive = false;
}

void Piece::collect(ITEMS collected)
{
	possesedItem = collected;

	return;
}
