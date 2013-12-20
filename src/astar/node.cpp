#include "astar/node.hpp"

#include <stdlib.h>

namespace astar
{
	Node::Node(int x, int y, Node* endnode)
	 :	pathfinding::Node(x, y),
	 	endnode(endnode),
		g(0),
		h(-1)
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

	Node* Node::getParent() const
	{
		return parent;
	}

	void Node::setParent(Node* parent)
	{
		this->parent = parent;
	}

	const std::vector<Node*>& Node::getChildren() const
	{
		return children;
	}

	void Node::addChild(Node* child)
	{
		children.push_back(child);
	}

	bool Node::operator==(const Node& rhs)
	{
		return (getX() == rhs.getX() && getY() == rhs.getY());
	}
}
