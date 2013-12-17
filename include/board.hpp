#ifndef BOARD_HPP
#define BOARD_HPP

class Square;

class Board
{
	public:
		Board(int width, int height);
		~Board();

		Square* getSquare(int x, int y);

		int getWidth() const;
		int getHeight() const;

	private:
		int width;
		int height;

		Square* squares;

};

#endif