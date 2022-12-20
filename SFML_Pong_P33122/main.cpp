#include "settings.h"
#include "functions.h"
#include "game.h"
using namespace sf;
int main()
{
	srand(time(nullptr));
	Game game;
	initGame(game);
	
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (game.window.isOpen())
	{
		//1 Обрабатываем очередь событий в цикле
		Event event;
		while (game.window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				game.window.close();
		}

		//2 Обновление объектов
		game.ball.shape.move(game.ball.speedX, game.ball.speedY);
		Vector2f midLeft{ 
			game.ball.shape.getPosition().x, 
			game.ball.shape.getPosition().y + BALL_RADIUS 
		};
		Vector2f midTop{ 
			game.ball.shape.getPosition().x + BALL_RADIUS,
			game.ball.shape.getPosition().y 
		};
		Vector2f midRight{ 
			game.ball.shape.getPosition().x + 2 * BALL_RADIUS,
			game.ball.shape.getPosition().y + BALL_RADIUS 
		};
		Vector2f midBottom{ 
			game.ball.shape.getPosition().x + BALL_RADIUS,
			game.ball.shape.getPosition().y + 2 * BALL_RADIUS 
		};
		 
		if (game.ball.shape.getPosition().x <= 0) 
		{
			ballReboundX(game.ball.speedX, game.rightPlayerScore,
				game.rightPlayerScoreText);
			initBall(game.ball);
		}
		if (game.ball.shape.getPosition().x >=
			WINDOW_WIDTH - 2 * BALL_RADIUS)
		{
			ballReboundX(game.ball.speedX, game.leftPlayerScore,
				game.leftPlayerScoreText);
			initBall(game.ball);
		}
	
		if (game.ball.shape.getPosition().y <= 0 ||
			game.ball.shape.getPosition().y >=
			(WINDOW_HEIGHT - 2 * BALL_RADIUS)
			)
			game.ball.speedY = -game.ball.speedY;
		//отбивание мяча от ракеток
		// левой ракетки
		if (pointInRect(game.leftBat, midLeft))
			game.ball.speedX = -game.ball.speedX;
		if (pointInRect(game.leftBat, midTop) || pointInRect(game.leftBat, midBottom))
			game.ball.speedY = -game.ball.speedY;
		//правой ракетки
		if (pointInRect(game.rightBat, midRight))
			game.ball.speedX = -game.ball.speedX;
		if (pointInRect(game.rightBat, midTop) || pointInRect(game.rightBat, midBottom))
			game.ball.speedY = -game.ball.speedY;
		//управление ракетками
		controlBat(game.leftBat, Keyboard::W, Keyboard::S);
		controlBat(game.rightBat, Keyboard::Up, Keyboard::Down);
		//отрисовка
		drawAll(game);
	}
	return 0;
}