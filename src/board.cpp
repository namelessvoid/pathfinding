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

Square* Board::getSquare(int x, int y)
{
	if(x < 0 || x > width || y < 0 || y > height)
		return 0;

	return &squares[y * height + x];
}