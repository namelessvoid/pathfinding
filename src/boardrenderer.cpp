#include "boardrenderer.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "board.hpp"

BoardRenderer::BoardRenderer(Board& board)
	:	board(board)
{}

void BoardRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape shape(50);

	// set the shape color to green
	shape.setFillColor(sf::Color(100, 250, 50));

	target.draw(shape);
}