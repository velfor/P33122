#pragma once
#include "SFML/Graphics.hpp"

struct Bat {
	sf::RectangleShape shape;
	float speedY;
};

struct Ball {
	sf::CircleShape shape;
	float speedX, speedY;
};

struct Game
{
	sf::RenderWindow window;
	Bat leftBat, rightBat;
	Ball ball;
	sf::Font font;
	sf::Text leftPlayerScoreText, rightPlayerScoreText;
};