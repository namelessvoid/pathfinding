#include "boardrenderer.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <iostream>

#include "board.hpp"
#include "square.hpp"
#include "path.hpp"

namespace pathfinding
{
	BoardRenderer::BoardRenderer(Board& board)
		:	board(board),
			path(0),
			emptycolor(81, 149, 81),
			wallcolor(97, 97, 97),
			startcolor(76, 76, 187),
			endcolor(223, 0, 0)
	{}

	void BoardRenderer::setPath(Path* path)
	{
		this->path = path;
	}

	void BoardRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		sf::Vector2u targetsize = target.getSize();
		int boardwidth = board.getWidth();
		int boardheight = board.getHeight();

		float squaredimension = targetsize.y > targetsize.x
			? targetsize.x / boardwidth : targetsize.y / boardheight;

		drawBoard(squaredimension, target, states);
	}

	void BoardRenderer::drawBoard(float squaredimension, sf::RenderTarget& target, sf::RenderStates states) const
	{
		int boardwidth = board.getWidth();
		int boardheight = board.getHeight();

		sf::RectangleShape shape(sf::Vector2f(squaredimension, squaredimension));
		shape.setOutlineThickness(1);
		shape.setOutlineColor(sf::Color::Black);

		for(int x = 0; x < boardwidth; ++x)
		{
			for(int y = 0; y < boardheight; ++y)
			{
				shape.setPosition(x * squaredimension, y * squaredimension);

				switch(board.getSquare(x, y)->getContent())
				{
					case Square::EC_WALL:
						shape.setFillColor(wallcolor);
						break;
					case Square::EC_START:
						shape.setFillColor(startcolor);
						break;
					case Square::EC_END:
						shape.setFillColor(endcolor);
						break;
					case Square::EC_EMPTY: // fall through
					default:
						shape.setFillColor(emptycolor);
						break;
				}

				target.draw(shape);
			}
		}
	}
}
