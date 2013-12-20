#ifndef NODE_HPP
#define NODE_HPP

#include "coordinates.hpp"

namespace pathfinding
{
	class Node
	{
		public:
			Node(int x, int y);

			int getX() const;
			int getY() const;
			const Coordinates& getCoordinates() const;

			bool operator==(const Node& rhs);

		private:
			Coordinates coordinates;
	};
}

#endif
