#include "settings.h"
#include "functions.h"
#include "game.h"
using namespace sf;
int main()
{
	srand(time(nullptr));
	Game game;
	game.window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	game.window.setFramerateLimit(FPS);
	initBat(game.leftBat, leftBatColor, leftBatStartPos);
	initBat(game.rightBat, rightBatColor, rightBatStartPos);
	initBall(game.ball);

	int leftPlayerScore = 0;
	int rightPlayerScore = 0;
	
	game.font.loadFromFile("ds-digib.ttf");
	initText(game.leftPlayerScoreText, leftPlayerScore, game.font, charSize, leftTextStartPos);
	initText(game.rightPlayerScoreText, rightPlayerScore, game.font, charSize, rightTextStartPos);
	
	// √лавный цикл приложени€. ¬ыполн€етс€, пока открыто окно
	while (game.window.isOpen())
	{
		//1 ќбрабатываем очередь событий в цикле
		Event event;
		while (game.window.pollEvent(event))
		{
			// ѕользователь нажал на Ђкрестикї и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				game.window.close();
		}

		//2 ќбновление объектов
		//шарик
		//движение шарика
		game.ball.shape.move(game.ball.speedX, game.ball.speedY);
		Vector2f midLeft{ game.ball.shape.getPosition().x, game.ball.shape.getPosition().y + BALL_RADIUS };
		Vector2f midTop{ game.ball.shape.getPosition().x + BALL_RADIUS, game.ball.shape.getPosition().y };
		Vector2f midRight{ game.ball.shape.getPosition().x + 2 * BALL_RADIUS, game.ball.shape.getPosition().y + BALL_RADIUS };
		Vector2f midBottom{ game.ball.shape.getPosition().x + BALL_RADIUS, game.ball.shape.getPosition().y + 2 * BALL_RADIUS };
		//попал-вышел за левую 
		if (game.ball.shape.getPosition().x <= 0) {
			ballReboundX(game.ball.speedX, rightPlayerScore,
				game.rightPlayerScoreText);
			initBall(game.ball);
			/*game.window.display();
			do {} while (!(Keyboard::isKeyPressed(Keyboard::Space)));*/
		}

		//или правую границу
		if (game.ball.shape.getPosition().x >=
			(WINDOW_WIDTH - 2 * BALL_RADIUS))
		{
			ballReboundX(game.ball.speedX, leftPlayerScore,
				game.leftPlayerScoreText);
			initBall(game.ball);
			/*game.window.display();
			do {} while (!(Keyboard::isKeyPressed(Keyboard::Space)));*/
		}
		//верхн€€ или нижн€€ границы
		if (game.ball.shape.getPosition().y <= 0 ||
			game.ball.shape.getPosition().y >=
			(WINDOW_HEIGHT - 2 * BALL_RADIUS)
			)
			game.ball.speedY = -game.ball.speedY;
		//отбивание м€ча от ракеток
		// левой ракетки
		if (pointInRect(game.leftBat, midLeft))
			game.ball.speedX = -game.ball.speedX;
		if (pointInRect(game.leftBat, midTop) || pointInRect(game.leftBat, midBottom))
			game.ball.speedY = -game.ball.speedY;
		//права€
		if (pointInRect(game.rightBat, midRight))
			game.ball.speedX = -game.ball.speedX;
		if (pointInRect(game.rightBat, midTop) || pointInRect(game.rightBat, midBottom))
			game.ball.speedY = -game.ball.speedY;

		controlBat(game.leftBat, Keyboard::W, Keyboard::S);
		controlBat(game.rightBat, Keyboard::Up, Keyboard::Down);
		
		
		drawAll(game);
	}
	return 0;
}