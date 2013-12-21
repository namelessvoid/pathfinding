#include "boardrenderer.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include <iostream>

#include "tostring.hpp"
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
			startcolor(70, 210, 70),
			endcolor(223, 0, 0),
			nodecolor(76, 76, 187)
	{
		font.loadFromFile("Knigqst.ttf");
	}

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
		drawPath(squaredimension, target, states);
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

	void BoardRenderer::drawPath(float squaredimension, sf::RenderTarget& target, sf::RenderStates states) const
	{
		if(!path)
			return;

		float scale = 0.2;

		sf::CircleShape shape(squaredimension);
		shape.setOrigin(squaredimension, squaredimension);
		shape.scale(scale, scale);

		shape.setOutlineColor(sf::Color::Black);
		shape.setOutlineThickness(5);
		shape.setFillColor(nodecolor);

		sf::Text text;
		text.setFont(font);
		text.setCharacterSize(squaredimension);
		text.setColor(sf::Color::White);

		auto nodes = path->get();
		int counter = 0;
		for(auto node : nodes)
		{
			shape.setPosition(
				squaredimension * node->getX() + 0.5 * squaredimension,
				squaredimension * node->getY() + 0.5 * squaredimension
			);
			text.setPosition(squaredimension * node->getX(), squaredimension * node->getY());
			text.setString(intToString(counter));

			target.draw(shape);
			target.draw(text);

			counter++;
		}

		// Draw start / end node
		auto specialnode = *nodes.begin();
		shape.setFillColor(startcolor);
		shape.setPosition(
			squaredimension * specialnode->getX() + 0.5 * squaredimension,
			squaredimension * specialnode->getY() + 0.5 * squaredimension
		);
		target.draw(shape);

		specialnode = nodes.back();
		shape.setFillColor(endcolor);
		shape.setPosition(
			squaredimension * specialnode->getX() + 0.5 * squaredimension,
			squaredimension * specialnode->getY() + 0.5 * squaredimension
		);
		target.draw(shape);
	}
}
