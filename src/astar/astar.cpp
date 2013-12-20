#include "astar/astar.hpp"

namespace astar
{
	AStar::AStar()
	 :	board(0),
		start(0),
		end(0)
	{}

	void AStar::setBoard(pathfinding::Board* board)
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


	pathfinding::Path* AStar::getPath()
	{
		if(!start && !end)
			return 0;

		pathfinding::Path* path = new pathfinding::Path();
		path->addNode(start);
		path->addNode(end);
		return path;
	}
}
