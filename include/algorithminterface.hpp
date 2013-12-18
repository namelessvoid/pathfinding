#ifndef ALGORITHM_INTERFACE_HPP
#define ALGORITHM_INTERFACE_HPP

#include "path.hpp"

class Board;

class AlgorithmInterface
{
	public:
		virtual void setBoard(Board* board) = 0;
		virtual void setStart(int x, int y) = 0;
		virtual void setEnd(int x, int y) = 0;

		virtual Path* getPath() = 0;
};

#endif
