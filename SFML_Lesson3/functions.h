#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include "game.h"

void initBat(Bat& bat, const sf::Color batColor, const sf::Vector2f batPosition) 
{
	bat.batShape.setSize(batSize);
	bat.batShape.setFillColor(batColor);
	bat.batShape.setPosition(batPosition);
	bat.batSpeedY = 0.f;
}

void initBall(sf::CircleShape& ball, const sf::Color ballColor, const sf::Vector2f ballPosition)
{
	ball.setRadius(ballRadius);
	ball.setFillColor(ballColor);
	ball.setPosition(ballPosition);
}

void initText(sf::Text& scoreText, int score, sf::Font& font, 
	const int charSize, const sf::Vector2f textStartPos) {
	scoreText.setString(std::to_string(score));
	scoreText.setFont(font);
	scoreText.setCharacterSize(charSize);
	scoreText.setPosition(textStartPos);
}

void ballReboundX(float& ballSpeed, int& playerScore, 
	sf::Text& scoreText)
{
	ballSpeed = -ballSpeed;
	playerScore++;
	scoreText.setString(std::to_string(playerScore));
}

void controlBat(sf::RectangleShape& bat, float& batSpeedY, sf::Keyboard::Key up_key, sf::Keyboard::Key down_key) 
{
	if (sf::Keyboard::isKeyPressed(up_key)) batSpeedY = -BAT_SPEED;
	if (sf::Keyboard::isKeyPressed(down_key)) batSpeedY = BAT_SPEED;
	bat.move(0.f, batSpeedY);
	batSpeedY = 0;
}
void drawAll(sf::RenderWindow& window, 
	const sf::RectangleShape& leftBat, 
	const sf::RectangleShape& rightBat,
	const sf::CircleShape& ball, 
	const sf::Text& leftPlayerScoreText, 
	const sf::Text& rightPlayerScoreText) 
{
	window.clear();
	window.draw(leftBat);
	window.draw(rightBat);
	window.draw(ball);
	window.draw(leftPlayerScoreText);
	window.draw(rightPlayerScoreText);
	window.display();
}