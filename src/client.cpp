#include <iostream>
#include "window.hpp"
#include "cell/map.hpp"
#include "virtual/snake.hpp"

int main()
{
	c_Map map(800, 800);
	c_window window(sf::Vector2f{ 800,800 }, &map);

	window.run();

	c_Snake Snake(1, 5, 5, UP, &map, 3);
	while (true)
	{
		//Snake.Move();
		getchar();
	}



    return 0;
}