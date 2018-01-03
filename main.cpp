#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "Matrix.h"
#include "menu.h";
#include "Level.h"
#include "Picontrol.h"

using namespace std;


int main() {

	sf::RenderWindow window(sf::VideoMode(1600, 900), "Legendary Sword Quest");
	sf::RectangleShape shape(sf::Vector2f(250, 75));
	sf::RectangleShape shape2(sf::Vector2f(250, 75));
	shape.setFillColor(sf::Color::Black);



	//Picontrol testControl{};

	//testControl.start();

	//Menu startMenu{ "test" };
	//Level test{ "Data/Levels/map1.txt" };

	float posX{ 200 };
	float posY{ 200 };

	sf::RectangleShape block(sf::Vector2f(32, 32));
	block.setFillColor(sf::Color::Green);
	block.setOutlineColor(sf::Color::Yellow);
	block.setOutlineThickness(2);

	sf::Texture play;
	play.loadFromFile("player.png");


	sf::Sprite blockPlay(play);


	std::vector<std::vector<float>> thonkings;



	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				//testControl.stop();
				window.close();
			}
			
			

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
			//testControl.saveCalibration();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			//testControl.startCalibration();
		}
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			std::vector<float> tmp;
			tmp.push_back((rand() % 500 + 50));
			tmp.push_back((rand() % 200 + 50));
			
			if (rand() % 2 == 0) {
				tmp.push_back(0.1);
			}
			else
				tmp.push_back(-0.1);

			if (rand() % 2 == 0) {
				tmp.push_back(0.1);
			}
			else
				tmp.push_back(-0.1);

			thonkings.push_back(tmp);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			posY -= 0.1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			posY += 0.1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			posX -= 0.1;
			blockPlay.rotate(-0.1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			posX += 0.1;
			blockPlay.rotate(0.1);
		}
		

		//std::cout << testControl.getFixedX() << " : " << testControl.getFixedY() << std::endl;
		
		//posX += 0.3 * testControl.getX();
		//posY += 0.3 * testControl.getY();
		window.clear();


		for (int i{ 0 }; i < thonkings.size(); ++i) {
			if (thonkings[i][0] < 0) {
				thonkings[i][0] = 0;
				thonkings[i][2] = 0.1;
			}
			else if (thonkings[i][0] + 32 > window.getSize().x) {
				thonkings[i][0] = window.getSize().x - 32;
				thonkings[i][2] = -0.1;
			}
				

			if (thonkings[i][1] < 0) {
				thonkings[i][1] = 0;
				thonkings[i][3] = 0.1;
			}	
			else if (thonkings[i][1] + 32 > window.getSize().y) {
				thonkings[i][1] = window.getSize().y - 32;
				thonkings[i][3] = -0.1;
			}
			
			thonkings[i][0] += thonkings[i][2];
			thonkings[i][1] += thonkings[i][3];

			if (thonkings[i][0] > 0)
				blockPlay.rotate(0.1);
			else
				blockPlay.rotate(-0.1);

			blockPlay.setPosition(thonkings[i][0] + 16.f, thonkings[i][1] + 16.f);
			blockPlay.setOrigin(16, 16);
			window.draw(blockPlay);
		}

		/*
		
		if (posX < 0)
			posX = 0;
		else if (posX + 32 > window.getSize().x)
			posX = window.getSize().x - 32;

		if (posY < 0)
			posY = 0;
		else if (posY + 32 > window.getSize().y)
			posY = window.getSize().y - 32;
		
		*/
		//block.setRotation(-1*testControl.getPitch());
		//block.setPosition(posX, posY);
		//blockPlay.setPosition(posX + 16.f, posY + 16.f);
		//blockPlay.setOrigin(16, 16);

		//std::cout << "Test" << std::endl;



		

		//window.draw(blockPlay);

		//startMenu.draw(window);

		//window.setActive(false);
		//test.draw(window);
		//window.setActive(true);

		//Draw the map

		//Draw back objects

		
		

		//Draw all npcs

		//Draw players

		//Draw front objects
		window.display();

		//std::cin.get();
	}

	
	return 0;
}