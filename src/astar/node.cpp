#include "astar/node.hpp"

#include <stdlib.h>

namespace astar
{
	Node::Node(int x, int y, Node* endnode)
	 :	x(x),
		y(y),
		endnode(endnode),
		g(0),
		h(-1)
	{}

	int Node::getX()
	{
		return x;
	}

	int Node::getY()
	{
		return y;
	}

	int Node::getG()
	{
		return g;
	}

	void Node::setG(int g)
	{
		this->g = g;
	}

	int Node::getH()
	{
		if(h == -1)
			h = abs(this->getX() - endnode->getX()) + abs(this->getY() - endnode->getY());
		return h;
	}

	int Node::getF()
	{
		return getG() + getH();
	}

	Node* Node::getParent()
	{
		return parent;
	}

	void Node::setParent(Node* parent)
	{
		this->parent = parent;
	}

	std::vector<Node*>& Node::getChildren()
	{
		return children;
	}

	void Node::addChild(Node* child)
	{
		children.push_back(child);
	}
}
