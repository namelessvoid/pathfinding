#ifndef ASTAR_NODE_HPP
#define ASTAR_NODE_HPP

#include <vector>

namespace astar
{
	class Node
	{
		public:
			Node(int x, int y, Node* endnode);

			int getX();
			int getY();

			void setG(int g);
			int getG();

			int getH();

			int getF();

			Node* getParent();
			void setParent(Node* parent);

			std::vector<Node*>& getChildren();
			void addChild(Node* child);

		private:
			const int x;
			const int y;

			int g;
			int h;

			Node* parent;
			std::vector<Node*> children;

			Node* endnode;
	};
}

#endif
