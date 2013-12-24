#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/View.hpp>

#include "board.hpp"
#include "square.hpp"
#include "boardrenderer.hpp"
#include "algorithminterface.hpp"

#include "astar/astar.hpp"

int main(int arg, char* argv[])
{
	pathfinding::Board board(10, 10);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Pathfinding Visualizer", sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	window.setView(sf::View(sf::FloatRect(0, 0, 800, 600)));

	pathfinding::BoardRenderer boardrenderer(board);

	pathfinding::AlgorithmInterface* algorithm = new astar::AStar();
	algorithm->setStart(0, 0);
	algorithm->setEnd(9, 9);
	algorithm->setBoard(&board);
	pathfinding::Path* path = algorithm->getPath();

	boardrenderer.setPath(path);
	boardrenderer.resize(800, 600);

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();

			else if (event.type == sf::Event::Resized)
			{
				// update the view to the new size of the window
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
				boardrenderer.resize(event.size);
			}

			if(boardrenderer.handleEvent(event) == true)
			{
				delete path;
				path = algorithm->getPath();
				boardrenderer.setPath(path);
			}
		}

		// Rendering
		window.clear(sf::Color::Black);
		window.draw(boardrenderer);
		window.display();
	}

	return 0;
}
