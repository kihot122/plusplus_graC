#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"


class c_window :public sf::Drawable
{
	sf::RenderWindow window;

	sf::CircleShape shape; // just for test, to delete later
	int radius = 45.f;

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

public:
	c_window(int, int);
	c_window() = delete;
	~c_window() = default;

	void setShape();

	void run();

};