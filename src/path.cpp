#include "path.hpp"

namespace pathfinding
{
	std::vector<Node*>& Path::get()
	{
		return path;
	}

	void Path::addNode(Node* node)
	{
		path.push_back(node);
	}
}
