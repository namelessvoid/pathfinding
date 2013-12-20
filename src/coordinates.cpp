#include "coordinates.hpp"

namespace pathfinding
{
	Coordinates::Coordinates(int x, int y)
	{
		coordinates.first = x;
		coordinates.second = y;
	}

	void Coordinates::setX(int x)
	{
		coordinates.first = x;
	}

	int Coordinates::getX() const
	{
		return coordinates.first;
	}

	void Coordinates::setY(int y)
	{
		coordinates.second = y;
	}

	int Coordinates::getY() const
	{
		return coordinates.second;
	}

	bool Coordinates::operator==(const Coordinates& rhs)
	{
		return (getX() == rhs.getX() && getY() == rhs.getY());
	}
}
