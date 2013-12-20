#include "astar/astar.hpp"

namespace astar
{
	AStar::AStar()
	 :	board(0),
		start(0),
		end(0)
	{}

	void AStar::setBoard(Board* board)
	{
		this->board = board;
	}

	void AStar::setStart(int x, int y)
	{
		if(start) {
			delete start;
		}
		start = new Node(x, y, end);
	}

	void AStar::setEnd(int x, int y)
	{
		if(end)
			delete end;
		end = new Node(x, y, end);
	}


	Path* AStar::getPath()
	{
		Path* path = new Path();
		path->addSquare(board->getSquare(start->getX(), start->getY()));
		path->addSquare(board->getSquare(end->getX(), end->getY()));
		return 0;
	}
}
