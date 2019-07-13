#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"


class c_window :public sf::Drawable
{
	sf::RenderWindow window;
	sf::CircleShape shape; // just for test, to delete later

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

public:
	c_window();
	~c_window() = default;

	const int Width = 1600;
	const int Height = 1200;

	void run();

};