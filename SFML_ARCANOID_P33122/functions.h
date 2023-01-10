#pragma once
#include "SFML/Graphics.hpp"
#include "bat.h"

void checkEvents(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event)){
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void updateGame(Bat& bat) {
	batControl(bat);
	batReboundEdges(bat);
}

void checkCollisions() {}

void drawGame(sf::RenderWindow& window, Bat& bat) {
	window.clear();
	batDraw(window, bat);
	window.display();
}



