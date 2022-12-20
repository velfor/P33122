#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include "game.h"

void initBat(Bat& bat, const sf::Color batColor, const sf::Vector2f batPosition) 
{
	bat.shape.setSize(batSize);
	bat.shape.setFillColor(batColor);
	bat.shape.setPosition(batPosition);
	bat.speedY = 0.f;
}

void initBall(Ball& ball)
{
	ball.shape.setRadius(BALL_RADIUS);
	ball.shape.setFillColor(BALL_COLOR);
	ball.shape.setPosition(BALL_START_POS);
	float arr_speed[]{ -5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f };
	int index = rand() % 10;
	ball.speedX = arr_speed[index];
	index = rand() % 10;
	ball.speedY = arr_speed[index];
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
	playerScore++;
	scoreText.setString(std::to_string(playerScore));

}

void controlBat(Bat& bat, sf::Keyboard::Key up_key, sf::Keyboard::Key down_key) 
{
	if (sf::Keyboard::isKeyPressed(up_key)) bat.speedY = -BAT_SPEED;
	if (sf::Keyboard::isKeyPressed(down_key)) bat.speedY = BAT_SPEED;
	bat.shape.move(0.f, bat.speedY);
	bat.speedY = 0;
}
bool pointInRect(const Bat& bat, sf::Vector2f point) {
	return (point.x >= bat.shape.getPosition().x && point.x <= bat.shape.getPosition().x + BAT_WIDTH) &&
		(point.y >= bat.shape.getPosition().y && point.y <= bat.shape.getPosition().y + BAT_HEIGHT);
}
void drawAll(Game& game) 
{
	game.window.clear();
	game.window.draw(game.leftBat.shape);
	game.window.draw(game.rightBat.shape);
	game.window.draw(game.ball.shape);
	game.window.draw(game.leftPlayerScoreText);
	game.window.draw(game.rightPlayerScoreText);
	game.window.display();
}