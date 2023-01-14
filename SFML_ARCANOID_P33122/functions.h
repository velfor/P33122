#pragma once
#include "SFML/Graphics.hpp"
#include "bat.h"
#include "ball.h"

void checkEvents(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event)){
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void updateGame(Bat& bat, Ball& ball) {
	batUpdate(bat);
	ballUpdate(ball);
}

void checkCollisions(Bat& bat, Ball& ball) {
	//кто в кого попал, пересёкся и что с этим делать
	sf::Vector2f midLeft{
		ball.shape.getPosition().x,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	sf::Vector2f midTop{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y
	};
	sf::Vector2f midRight{
		ball.shape.getPosition().x + 2 * BALL_RADIUS,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	sf::Vector2f midBottom{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y + 2 * BALL_RADIUS
	};
}

void drawGame(sf::RenderWindow& window, const Bat& bat, 
	const Ball& ball) {
	window.clear();
	batDraw(window, bat);
	ballDraw(window, ball);
	window.display();
}



