#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#ifndef BUTTON_H
#define BUTTON_H

class Button {

public:
	//location of texture, position x,y
	Button(std::string, int, int);
	~Button() = default;

	void draw(sf::RenderWindow&);

private:
	sf::Texture tex;
	int x{ 0 };
	int y{ 0 };

};

#endif // !BUTTON_H

