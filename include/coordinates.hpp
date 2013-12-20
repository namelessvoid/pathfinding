#ifndef COORDINATES_HPP
#define COORDINATES_HPP

#include <utility>

namespace pathfinding
{
	class Coordinates
	{
		public:
			Coordinates(int x = 0, int y = 0);

			void setX(int x);
			int getX() const;

			void setY(int y);
			int getY() const;

			bool operator==(const Coordinates& coordinates);

		private:
			std::pair<int, int> coordinates;
	};
}

#endif
