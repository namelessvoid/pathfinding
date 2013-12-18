#ifndef ALGORITHM_INTERFACE
#define ALGORITHM_INTERFACE

class AlgorithmInterface
{
	public:
		virtual void setStartPoint(int x, int y) = 0;
		virtual void setEndPont(int x, int y) = 0;

		virtual Node* getPath() = 0;
};

#endif
