#include <SFML/Graphics.hpp>
#include "settings.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);

	//Создание объектов
	RectangleShape leftBat, rightBat;
	leftBat.setSize(BAT_SIZE);
	leftBat.setFillColor(LEFT_BAT_COLOR);
	leftBat.setPosition(BAT_OFFSET, (WINDOW_HEIGHT - BAT_SIZE.y) / 2);
	rightBat.setSize(BAT_SIZE);
	rightBat.setFillColor(RIGHT_BAT_COLOR);
	rightBat.setPosition(WINDOW_WIDTH - BAT_OFFSET - BAT_SIZE.x, (WINDOW_HEIGHT - BAT_SIZE.y) / 2);

	CircleShape ball(BALL_RADIUS);
	ball.setFillColor(BALL_COLOR);
	ball.setPosition((WINDOW_WIDTH - 2 * BALL_RADIUS) / 2, 
		(WINDOW_HEIGHT - 2 * BALL_RADIUS) / 2);

	float ballSpeedX = 2.f;
	float ballSpeedY = 3.f;

	while (window.isOpen())
	{
		//1 обработка событий
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		// Обновление игровых объектов
		//MЯЧ
		ball.move(ballSpeedX, ballSpeedY);
		if (ball.getPosition().x <= 0 ||
			ball.getPosition().x + 2 * BALL_RADIUS >= WINDOW_WIDTH)
		{
			ballSpeedX = -ballSpeedX;
		}
		if (ball.getPosition().y <= 0 ||
			ball.getPosition().y + 2 * BALL_RADIUS >= WINDOW_HEIGHT)
		{
			ballSpeedY = -ballSpeedY;
		}
		//ЛЕВАЯ РАКЕТКА
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			leftBat.move(0.f, -BAT_DY);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			leftBat.move(0.f, BAT_DY);
		}
		//ПРАВАЯ РАКЕТКА
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			leftBat.move(0.f, -BAT_DY);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			leftBat.move(0.f, BAT_DY);
		}
		//3 отрисовка объектов и обновление окна
		window.clear();
		window.draw(leftBat);
		window.draw(rightBat);
		window.draw(ball);
		window.display();
	}

	return 0;
}