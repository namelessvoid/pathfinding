#ifndef ASTAR_HPP
#define ASTAR_HPP

#include <vector>
#include <unordered_set>

#include "algorithminterface.hpp"
#include "board.hpp"
#include "astar/node.hpp"

namespace astar
{
	class AStar : public pathfinding::AlgorithmInterface
	{
		public:
			AStar();
			~AStar();

			void setBoard(pathfinding::Board* board);
			void setStart(int x, int y);
			void setEnd(int x, int y);

			pathfinding::Path* getPath();

		private:
			bool closedlistContains(Node* node);
			bool closedlistContainsCoords(const pathfinding::Coordinates& coordinates);
			bool openlistContainsCoords(const pathfinding::Coordinates& coordinates);
			Node* openListFindCoords(const pathfinding::Coordinates& coordinates);
			Node* findNextCurrentNode();
			int calcH(Node* node);

			pathfinding::Board* board;

			Node* start;
			Node* end;

			std::unordered_set<Node*> openlist;
			std::vector<Node*> closedlist;

			pathfinding::Coordinates directions[4];
	};
}

#endif
