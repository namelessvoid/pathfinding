#ifndef ALGORITHM_INTERFACE
#define ALGORITHM_INTERFACE

#include "path.hpp"

class AlgorithmInterface
{
	public:
		virtual void setStartPoint(int x, int y) = 0;
		virtual void setEndPont(int x, int y) = 0;

		virtual Path* getPath() = 0;
};

#endif
