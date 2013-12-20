#ifndef ASTAR_NODE_HPP
#define ASTAR_NODE_HPP

#include <vector>

#include "../node.hpp"

namespace astar
{
	class Node : public pathfinding::Node
	{
		public:
			Node(int x, int y);

			void setG(int g);
			int getG() const;

			void setH(int h);
			int getH() const;

			int getF() const;

			Node* getParent() const;
			void setParent(Node* parent);

			const std::vector<Node*>& getChildren() const;
			void addChild(Node* child);

		private:
			int g;
			int h;

			Node* parent;
			std::vector<Node*> children;
	};
}

#endif
