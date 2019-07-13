#include "window.hpp"

c_window::c_window(int width, int height)
	:window(sf::VideoMode(width, height), "test_window", sf::Style::Default)
{
}

void c_window::setShape()
{
	shape.setFillColor(sf::Color::Yellow);
	shape.setRadius(this->radius);
	shape.setOrigin(this->radius, this->radius);
	shape.setPosition(800, 800);
}

void c_window::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	//window.draw(this->shape, state); // error
}

void c_window::run()
{

	while (window.isOpen())
	{
		window.clear(sf::Color::Green);
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}


		window.draw(shape);

		window.display();
	}
}
