#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "board.hpp"
#include "boardrenderer.hpp"

int main(int arg, char* argv[])
{
	Board board(10, 10);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Pathfinding Visualizer", sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	BoardRenderer boardrenderer(board);

	while (window.isOpen())
	{
	    // check all the window's events that were triggered since the last iteration of the loop
	    sf::Event event;
	    while (window.pollEvent(event))
	    {
	        // "close requested" event: we close the window
	        if (event.type == sf::Event::Closed)
	            window.close();
	    }

	    // Rendering
	    window.clear(sf::Color::Black);
	    window.draw(boardrenderer);
	    window.display();
	}

	return 0;
}