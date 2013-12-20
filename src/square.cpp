#include "square.hpp"

namespace pathfinding
{
	Square::Square()
		:	content(EC_EMPTY)
	{}

	void Square::setContent(Square::Content content)
	{
		this->content = content;
	}

	Square::Content Square::getContent() const
	{
		return content;
	}
}
