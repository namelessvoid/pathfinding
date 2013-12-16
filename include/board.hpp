#ifndef BOARD_HPP
#define BOARD_HPP

class Square;

class Board
{
	public:
		Board(int width, int height);
		~Board();

	private:
		Square* squares;

};

#endif