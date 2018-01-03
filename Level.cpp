#include "Level.h"
#include <iostream>

Level::Level(std::string conf)
{
	//First line: Number of layers
	//Second line: Size of layer x,y
	//Layer

	//Next layer size
	//Layer
	//...

	if (!levelSheet.loadFromFile("Data/Blocks/levelSheet.png")) {
		std::cerr << "Unable to load level sheet" << std::endl;
	}

	std::ifstream file;

	file.open(conf);

	

	int amount{ 0 };
	int layX{ 0 };
	int layY{ 0 };

	file >> amount;
	

	for (int i{ 0 }; i < amount; ++i) {
		file >> layX;
		file >> layY;
		Matrix tmp{ layX, layY };
		tmp.fillWith(0);

		for (int j{ 0 }; j < layY; ++j) {
			for (int k{ 0 }; k < layX; ++k) {
				file >> tmp.at(k, j);
			}
		}

		layers.push_back(tmp);

	}
	



}

void Level::draw(sf::RenderWindow & window)
{

	window.setActive(true);
	sf::Sprite block{ levelSheet };
	sf::IntRect blockRect{ 0,0,32,32 };

	//std::cout << "going into draw: " << layers.size() << std::endl;
	/*
	for (int i{ 0 }; i < layers.size(); ++i) {
		for (int j{ 0 }; j < layers[i].sizeY(); ++j) {
			for (int k{ 0 }; k < layers[i].sizeX(); ++k) {

				//Draw the map using one spritesheet + IntRect system
				if (layers[i].at(k, j) < 8)
					blockRect.left = layers[i].at(k, j) * 32;
				else {
					blockRect.left = 0;
					blockRect.top = 32;
				}
					

				blockRect.top = layers[i].at(k, j) / 8;
				block.setTextureRect(blockRect);
				block.setPosition(k * 32, j * 32);
				window.draw(block);
				std::cout << "Drawing: " << layers[i].at(k, j) << std::endl;
			}
		}
	}
	*/

	/*
	for (int i{ 0 }; i < 8; ++i) {
		blockRect.left = 32 * i;
		block.setTextureRect(blockRect);
		block.setPosition(i * 32, 0);
		window.draw(block);
	}
	*/

	for (int i{ 0 }; i < layers[0].sizeY(); ++i) {
		for (int j{ 0 }; j < layers[0].sizeX(); ++j) {

			if (layers[0].at(j, i) == 9) {
				blockRect.left = 0;
				blockRect.top = 32;
			}
			else {
				blockRect.left = layers[0].at(j, i) * 32;
				blockRect.top = 0;
			}

			block.setTextureRect(blockRect);
			block.setPosition(j*32, i*32);
			window.draw(block);

		}
	}

	

	window.setActive(false);


}
