#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "button.h"
#ifndef MENU_H
#define MENU_H

class Menu {

public:
	Menu(std::string conf);
	~Menu() = default;

	void draw(sf::RenderWindow& window);

private:
	std::vector<Button> buttons;
	sf::Texture background;


};

#endif MENU_H

