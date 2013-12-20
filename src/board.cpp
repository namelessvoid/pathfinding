#include "board.hpp"

#include "coordinates.hpp"
#include "square.hpp"

namespace pathfinding
{
	Board::Board(int width, int height)
		:	width(width),
			height(height)
	{
		squares = new Square[width * height];
	}

	Board::~Board()
	{
		delete[] squares;
	}

	Square* Board::getSquare(int x, int y) const
	{
		if(x < 0 || x > width || y < 0 || y > height)
			return 0;

		return &squares[y * height + x];
	}

	Square* Board::getSquare(const Coordinates& coordinates) const
	{
		return getSquare(coordinates.getX(), coordinates.getY());
	}

	int Board::getWidth() const
	{
		return width;
	}

	int Board::getHeight() const
	{
		return height;
	}
}
