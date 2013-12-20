#ifndef BOARD_HPP
#define BOARD_HPP

class Coordinates;
class Square;

class Board
{
	public:
		Board(int width, int height);
		~Board();

		Square* getSquare(int x, int y) const;
		Square* getSquare(const Coordinates& cordinates) const;

		int getWidth() const;
		int getHeight() const;

	private:
		int width;
		int height;

		Square* squares;

};

#endif
