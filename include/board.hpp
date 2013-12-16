#ifndef BOARD_HPP
#define BOARD_HPP

class Square;

class Board
{
	public:
		Board(int height, int width);
		~Board();

	private:
		Square* squares;

};

#endif