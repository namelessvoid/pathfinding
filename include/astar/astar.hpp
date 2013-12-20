#ifndef ASTAR_HPP
#define ASTAR_HPP

#include <vector>
#include <unordered_set>

#include "algorithminterface.hpp"
#include "board.hpp"
#include "astar/node.hpp"

namespace astar
{
	class AStar : public AlgorithmInterface
	{
		public:
			AStar();
			~AStar();

			void setBoard(Board* board);
			void setStart(int x, int y);
			void setEnd(int x, int y);

			Path* getPath();

		private:
			Board* board;

			Node* start;
			Node* end;

			std::unordered_set<Node*> openlist;
			std::vector<Node*> closedlist;
	};
}

#endif
