#pragma once
#include "SFML/Graphics.hpp"

struct Bat {
	sf::RectangleShape batShape;
	float batSpeedY;
};

struct Ball {
	sf::CircleShape ball;
	float ballSpeedX, ballSpeedY;
};

struct Game
{
	sf::RenderWindow window;
	Bat leftBat, rightBat;
	Ball ball;
	sf::Font font;
	sf::Text leftPlayerScoreText, rightPlayerScoreText;
};