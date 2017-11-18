#include "menu.h"

Menu::Menu(std::string conf)
{
	if (!background.loadFromFile("Data/Menu/bluebg.png")) {
		//cerr << "Error loading" << endl;
	}

	Button tmp1{ "Data/Menu/button_start.png",  600, 600 };
	Button tmp2{ "Data/Menu/exit_button.png" , 600, 700 };

	buttons.push_back(tmp1);

	buttons.push_back(tmp2);
}

void Menu::draw(sf::RenderWindow & window)
{
	window.setActive(true);
	sf::Sprite back{ background };
	window.draw(back);


	window.setActive(false);
	for (int i{ 0 }; i < buttons.size(); ++i) {
		//set window active inside button and deactivate after drawing the button is complete
		buttons[i].draw(window);
	}
	window.setActive(true);

	//Draw more things for the menu

	window.setActive(false);
	//Menu drawing complete

}
