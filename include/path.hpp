#ifndef PATH_HPP
#define PATH_HPP

#include <vector>

#include "square.hpp"

class Path
{
	public:
		std::vector<Square*>& get();
		void addSquare(Square* square);

	private:
		std::vector<Square*> path;
};

#endif
