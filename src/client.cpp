#include <iostream>
#include "window.hpp"


int main()
{
	c_Map map(800, 800);
	c_window window(sf::Vector2f{ 800,800 }, &map);

	window.run();


    return 0;
}