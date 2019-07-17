#include "window.hpp"



c_window::c_window(sf::Vector2f windowSize)
	:window({ (unsigned int)windowSize.x, (unsigned int)windowSize.y, 32 }, "Snake", sf::Style::Default)
{
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