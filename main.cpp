#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Matrix.h"


using namespace std;


int main() {

	sf::RenderWindow window(sf::VideoMode(1600, 900), "Legendary Sword Quest");
	sf::RectangleShape shape(sf::Vector2f(250, 75));
	sf::RectangleShape shape2(sf::Vector2f(250, 75));
	shape.setFillColor(sf::Color::Black);

	sf::Texture tex;
	sf::Texture tex1;
	sf::Texture tex2;

	if (!tex.loadFromFile("Data/Menu/bluebg.png")) {
		cerr << "Error loading" << endl;
	}

	if (!tex1.loadFromFile("Data/Menu/button_start.png")) {

	}

	if (!tex2.loadFromFile("Data/Menu/exit_button.png")) {

	}

	sf::Sprite background;
	sf::Sprite button;

	background.setTexture(tex);
	button.setTexture(tex1);


	button.setPosition(600, 600);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		//Draw the map

		//Draw back objects
		window.draw(background);
		
		//Draw all npcs
		button.setPosition(600, 600);
		button.setTexture(tex1);
		window.draw(button);

		button.setPosition(600, 700);
		button.setTexture(tex2);
		window.draw(button);
		//Draw players

		//Draw front objects
		window.display();
	}

	
	return 0;
}