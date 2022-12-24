#pragma once
#include "SFML/Graphics.hpp"
#include "bat.h"

void batInit(Bat& bat) {
	bat.shape.setSize(sf::Vector2f(BAT_WIDTH, BAT_HEIGHT));
	bat.shape.setFillColor(BAT_COLOR);
	bat.shape.setPosition(BAT_START_POS);
	bat.speedx = 0.f;
}

void batControl(Bat& bat) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		bat.speedx = -BAT_SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		bat.speedx = BAT_SPEED;
	bat.shape.move(bat.speedx, 0.f);
	bat.speedx = 0.f;
}

void batReboundEdges(Bat& bat) {
	float batx = bat.shape.getPosition().x;
	float baty = bat.shape.getPosition().y;

	if (batx <= 0) bat.shape.setPosition(0.f, baty);

	if (batx >= WINDOW_WIDTH - BAT_WIDTH)
		bat.shape.setPosition(WINDOW_WIDTH - BAT_WIDTH, baty);

}

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

void drawGame(sf::RenderWindow& window, Bat bat) {
	window.clear();
	window.draw(bat.shape);
	window.display();
}



