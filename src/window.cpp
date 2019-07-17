#include "window.hpp"
#include "enum.hpp"
#include <iostream>

c_window::c_window(sf::Vector2f windowSize, c_Map* map)
	:window({ (unsigned int)windowSize.x, (unsigned int)windowSize.y, 32 }, "Snake", sf::Style::Default), map(map)
{
}

void c_window::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < map->GetSize()[0]; i++)
	{
		for (int j = 0; j < map->GetSize()[1]; j++)
		{
			sf::RectangleShape shape;
			shape.setSize({ 64,64 });
			shape.setPosition({ i*64,j*64 });
			switch (map->GetCell(i, j)->GetID())
			{
			case CELL_EMPTY:

				break;
			case CELL_FRUIT:

				break;
			case CELL_WALL:

				break;
			case c_SNAKE_HEAD:

				break;
			case c_SNAKE_TAIL:

				break;
			default:
				std::cout << "no cell matching\n";
				break;
			}
			target.draw(shape);
		}
	}
}

void c_window::run() // <- function to printing out
{

	while (window.isOpen())
	{
		window.clear({ 0,0,0 });

		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}

		}

		window.display();
	}

}