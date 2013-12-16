#ifndef BOARD_HPP
#define BOARD_HPP

#include "square.hpp"

class Board
{
	public:
		Board(int height, int width);
		~Board();
		
	private:
		Square* squares;

};

#endif