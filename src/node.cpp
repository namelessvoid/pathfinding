#include "node.hpp"

#include <stdlib.h>

namespace pathfinding
{
	Node::Node(int x, int y)
	 :	coordinates(x, y),
	 	parent(0)
	{}

	int Node::getX() const
	{
		return coordinates.getX();
	}

	int Node::getY() const
	{
		return coordinates.getY();
	}

	const Coordinates& Node::getCoordinates() const
	{
		return coordinates;
	}

	Node* Node::getParent() const
	{
		return parent;
	}

	void Node::setParent(Node* parent)
	{
		this->parent = parent;
	}

	bool Node::operator==(const Node& rhs)
	{
		return (getX() == rhs.getX() && getY() == rhs.getY());
	}
}
