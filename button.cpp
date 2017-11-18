#include "button.h"

Button::Button(std::string file, int x, int y)
{
	if (!tex.loadFromFile(file)) {
		std::cerr << "Couldn't load file: " << file << std::endl;
	}

	this->x = x;
	this->y = y;

}

void Button::draw(sf::RenderWindow & window)
{
	window.setActive(true);
	sf::Sprite but{ tex };
	but.setPosition(x, y);
	window.draw(but);
	window.setActive(false);
}
