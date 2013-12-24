#ifndef BOARDRENDERER_HPP
#define BOARDRENDERER_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>

namespace pathfinding
{
	class Board;
	class Path;

	class BoardRenderer : public sf::Drawable
	{
		public:
			BoardRenderer(Board& board);

			void setPath(Path* path);

			bool handleEvent(const sf::Event &event);

			void resize(float widht, float height);
			void resize(const sf::Event::SizeEvent& event);
			void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		private:
			void drawBoard(float squaredimension, sf::RenderTarget& target, sf::RenderStates states) const;
			void drawPath(float squaredimension, sf::RenderTarget& target, sf::RenderStates states) const;

			float squaredimension;

			Board& board;

			Path* path;

			sf::Color emptycolor;
			sf::Color wallcolor;
			sf::Color startcolor;
			sf::Color endcolor;
			sf::Color nodecolor;

			sf::Font font;
	};
}

#endif
