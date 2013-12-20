#ifndef PATH_HPP
#define PATH_HPP

#include <vector>

#include "node.hpp"

namespace pathfinding
{
	class Path
	{
		public:
			std::vector<Node*>& get();
			void addNode(Node* node);

		private:
			std::vector<Node*> path;
	};
}

#endif
