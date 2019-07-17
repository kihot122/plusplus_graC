#pragma once
#include "SFML/Graphics.hpp"
#include "cell/map.hpp"

class c_window
{
	sf::RenderWindow window;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	c_Map* map;

public:
	c_window(sf::Vector2f windowSize, c_Map* map);

	void run();
};