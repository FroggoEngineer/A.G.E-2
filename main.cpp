#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Matrix.h"
#include "menu.h";


using namespace std;


int main() {

	sf::RenderWindow window(sf::VideoMode(1600, 900), "Legendary Sword Quest");
	sf::RectangleShape shape(sf::Vector2f(250, 75));
	sf::RectangleShape shape2(sf::Vector2f(250, 75));
	shape.setFillColor(sf::Color::Black);




	Menu startMenu{ "test" };


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		startMenu.draw(window);

		//Draw the map

		//Draw back objects

		
		

		//Draw all npcs

		//Draw players

		//Draw front objects
		window.display();
	}

	
	return 0;
}