#include "board.hpp"

#include "square.hpp"

Board::Board(int width, int height)
{
	squares = new Square[width * height];
}

Board::~Board()
{
	delete[] squares;
}