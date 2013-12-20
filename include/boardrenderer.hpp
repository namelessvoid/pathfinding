#ifndef BOARDRENDERER_HPP
#define BOARDRENDERER_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Color.hpp>

namespace pathfinding
{
	class Board;
	class Path;

	class BoardRenderer : public sf::Drawable
	{
		public:
			BoardRenderer(Board& board);

			void setPath(Path* path);

			void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		private:
			void drawBoard(float squaredimension, sf::RenderTarget& target, sf::RenderStates states) const;
			void drawPath(float squaredimension, sf::RenderTarget& target, sf::RenderStates states) const;

			Board& board;

			Path* path;

			sf::Color emptycolor;
			sf::Color wallcolor;
			sf::Color startcolor;
			sf::Color endcolor;
			sf::Color nodecolor;
	};
}

#endif
