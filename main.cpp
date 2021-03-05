#include "board.hpp"

int main()
{
	LOG->writeToLog("Starting new game...", LOG_COLOR::GREEN);
	BOARD->drawBoard();

	LOG->writeToLog("Shutting down program...", LOG_COLOR::GREEN);
	return 0;
}