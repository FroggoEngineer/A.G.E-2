#pragma once
#include "Matrix.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>

#ifndef LEVEL_H
#define LEVEL_H

class Level {

public:
	Level(std::string conf);
	~Level() = default;


	void draw(sf::RenderWindow&);

private:

	std::vector<Matrix> layers;
	sf::Texture levelSheet;

};

#endif // !LEVEL_H

