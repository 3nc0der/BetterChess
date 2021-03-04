#include "board.hpp"

int main()
{
	LOG->mf_writeToLog("Starting new game...", GREEN);
	BOARD->drawBoard();

	LOG->mf_writeToLog("Shutting down program...", GREEN);
	return 0;
}