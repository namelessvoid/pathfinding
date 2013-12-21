#include "astar/node.hpp"

#include <stdlib.h>
#include <climits>

namespace astar
{
	Node::Node(int x, int y)
	 : 	pathfinding::Node(x, y),
		g(INT_MAX),
		h(INT_MAX)
	{}

	int Node::getG() const
	{
		return g;
	}

	void Node::setG(int g)
	{
		this->g = g;
	}

	int Node::getH() const
	{
		return h;
	}

	void Node::setH(int h)
	{
		this->h = h;
	}

	int Node::getF() const
	{
		return getG() + getH();
	}

	const std::vector<Node*>& Node::getChildren() const
	{
		return children;
	}

	void Node::addChild(Node* child)
	{
		children.push_back(child);
	}
}
