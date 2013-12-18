#include "path.hpp"

std::vector<Square*>& Path::get()
{
	return path;
}

void Path::addSquare(Square* square)
{
	path.push_back(square);
}
