#ifndef BOARDRENDERER_HPP
#define BOARDRENDERER_HPP

#include <SFML/Graphics/Drawable.hpp>
// #include <SFML/Graphics/RenderTarget.hpp>
// #include <SFML/Graphics/RenderStates.hpp>

class Board;

class BoardRenderer : public sf::Drawable
{
	public:
		BoardRenderer(Board& board);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		Board& board;
};

#endif