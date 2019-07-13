/*#include "window.hpp"

c_window::c_window()
	:window(sf::VideoMode(Width, Height), "test_window", sf::Style::Default)
{
}

void c_window::run()
{

	while (window.isOpen())
	{
		window.clear(sf::Color::Black);
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		window.display();
	}
}*/
