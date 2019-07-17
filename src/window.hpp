#pragma once
#include "SFML/Graphics.hpp"

class c_window
{
	sf::RenderWindow window;


public:
	c_window(sf::Vector2f windowSize);

	void run();
};