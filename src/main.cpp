#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "board.hpp"

int main(int arg, char* argv[])
{
	Board board(10, 10);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Pathfinding Visualizer", sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);

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
	}

	return 0;
}