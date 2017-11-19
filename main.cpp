#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Matrix.h"
#include "menu.h";
#include "Level.h"

using namespace std;


int main() {

	sf::RenderWindow window(sf::VideoMode(1600, 900), "Legendary Sword Quest");
	sf::RectangleShape shape(sf::Vector2f(250, 75));
	sf::RectangleShape shape2(sf::Vector2f(250, 75));
	shape.setFillColor(sf::Color::Black);




	Menu startMenu{ "test" };
	Level test{ "Data/Levels/map1.txt" };

	cout << "testing" << endl;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Check for input
		//----------------------------


		//----------------------------


		window.clear();


		//startMenu.draw(window);

		window.setActive(false);
		test.draw(window);
		window.setActive(true);

		//Draw the map

		//Draw back objects

		
		

		//Draw all npcs

		//Draw players

		//Draw front objects
		window.display();
	}

	
	return 0;
}