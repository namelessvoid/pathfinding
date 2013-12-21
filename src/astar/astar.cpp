#include "astar/astar.hpp"

#include <iostream>
#include <cmath>

#include "square.hpp"

namespace astar
{
	AStar::AStar()
	 :	board(0),
		start(0),
		end(0)
	{
		directions[0].setX(-1);
		directions[1].setY(-1);
		directions[2].setX(+1);
		directions[3].setY(+1);
	}

	void AStar::setBoard(pathfinding::Board* board)
	{
		this->board = board;
	}

	void AStar::setStart(int x, int y)
	{
		if(start) {
			delete start;
		}
		start = new Node(x, y);
		start->setG(0);
	}

	void AStar::setEnd(int x, int y)
	{
		if(end)
			delete end;
		end = new Node(x, y);
	}


	pathfinding::Path* AStar::getPath()
	{
		if(!start && !end && !board)
			return 0;

		Node* newnode = 0;
		Node* currentnode = 0;
		openlist.insert(start);

		start->setG(0);
		start->setH(calcH(start));

		while(!openlist.empty() && !closedlistContains(end))
		{
			// Manage new next current node.
			currentnode = findNextCurrentNode();
			closedlist.push_back(currentnode);

			// Check the adjacent squares.
			const pathfinding::Coordinates& coordinates = currentnode->getCoordinates();
			for(int i = 0; i < 4; ++i)
			{
				pathfinding::Coordinates tmpcoords = coordinates + directions[i];
				pathfinding::Square* square = board->getSquare(tmpcoords.getX(), tmpcoords.getY());

				if(square != 0
				   // Is walkable?
				   && square->getContent() != pathfinding::Square::Content::EC_WALL
				   // Not on closedlist?
				   && !closedlistContainsCoords(tmpcoords))
				{
					std::cout << "iterating adjacent square...\n";
					newnode = new Node(tmpcoords.getX(), tmpcoords.getY());
					if(openListFindCoords(tmpcoords) == 0)
					{
						std::cout << "new node...\n";
						newnode->setG(currentnode->getG() + 1);
						newnode->setH(calcH(newnode));

						openlist.insert(newnode);
						newnode->setParent(currentnode);
					}
					else
					{
						std::cout << "old node\n";
						delete newnode;
						newnode = openListFindCoords(tmpcoords);
						if(newnode->getG() > (currentnode->getG() + 1))
						{
							newnode->setParent(currentnode);
							newnode->setG(currentnode->getG() + 1);
						}
					}
				}
			}
		}

		// Create Path.
		pathfinding::Path* path = new pathfinding::Path();
		std::cout << "parent of end node: " << end->getParent() << std::endl;
		for(pathfinding::Node* iter = closedlist.back(); iter->getParent() != 0; iter = iter->getParent())
		{
			path->prependNode(iter);
		}
		path->prependNode(start);
		return path;
	}

	bool AStar::closedlistContains(Node* node)
	{
		return closedlistContainsCoords(node->getCoordinates());
	}

	bool AStar::closedlistContainsCoords(const pathfinding::Coordinates& coordinates)
	{
		for(auto nodeiter : closedlist)
		{
			if(nodeiter->getX() == coordinates.getX() && nodeiter->getY() == coordinates.getY())
				return true;
		}
		return false;
	}

	bool AStar::openlistContainsCoords(const pathfinding::Coordinates& coordinates)
	{
		for(auto nodeiter : openlist)
		{
			if(nodeiter->getX() == coordinates.getX() && nodeiter->getY() == coordinates.getY())
				return true;
		}
		return false;
	}

	Node* AStar::findNextCurrentNode()
	{
		if(openlist.empty())
			return 0;

		auto minnodeiter = openlist.begin();

		for(auto nodeiter = openlist.begin(); nodeiter != openlist.end(); ++nodeiter)
		{
			if((*nodeiter)->getF() < (*minnodeiter)->getF())
				minnodeiter = nodeiter;
		}

		openlist.erase(minnodeiter);
		return *minnodeiter;
	}

	Node* AStar::openListFindCoords(const pathfinding::Coordinates& coordinates)
	{
		for(auto nodeiter : openlist)
		{
			if(nodeiter->getX() == coordinates.getX() && nodeiter->getY() == coordinates.getY())
				return nodeiter;
		}
		return 0;
	}

	int AStar::calcH(Node* node)
	{
		if(!end)
			return 0;

		return abs(end->getX() - node->getX()) + abs(end->getY() - node->getY());
	}
}
