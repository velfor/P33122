#include "settings.h"
#include "functions.h"
#include "game.h"
using namespace sf;

int main()
{
	srand(time(nullptr));
	/*
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);*/
	Game game;
	game.window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	game.window.setFramerateLimit(FPS);
	//создание объектов игры
	//ракетки
	RectangleShape leftBat, rightBat;
	initBat(game.leftBat, leftBatColor, leftBatStartPos);
	initBat(game.rightBat, rightBatColor, rightBatStartPos);
	

	//шарик
	CircleShape ball;
	initBall(ball, ballColor, ballStartPosition);
	float arr_speed[]{ -5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f };
	int index = rand() % 10;
	float ball_speedx = arr_speed[index];
	index = rand() % 10;
	float ball_speedy = arr_speed[index];

	//СЧЕТ
	int leftPlayerScore = 0;
	int rightPlayerScore = 0;
	
	//шрифт
	Font font;
	font.loadFromFile("ds-digib.ttf");
	//тексты для счета
	Text leftPlayerScoreText;
	initText(leftPlayerScoreText, leftPlayerScore, font, charSize, leftTextStartPos);

	Text rightPlayerScoreText;
	initText(rightPlayerScoreText, rightPlayerScore, font, charSize, rightTextStartPos);
	
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
		//шарик
		//движение шарика
		ball.move(ball_speedx, ball_speedy);
		//попал-вышел за левую 
		if (ball.getPosition().x <= 0)
			ballReboundX(ball_speedx, rightPlayerScore,
				rightPlayerScoreText);

		//или правую границу
		if (ball.getPosition().x >=(WINDOW_WIDTH - 2 * ballRadius))
			ballReboundX(ball_speedx, leftPlayerScore,
				leftPlayerScoreText);
		//верхняя или нижняя границы
		if (ball.getPosition().y <= 0 || ball.getPosition().y >=
			(WINDOW_HEIGHT - 2 * ballRadius))
			ball_speedy = -ball_speedy;

		controlBat(leftBat, leftBatSpeedY, Keyboard::W, Keyboard::S);
		controlBat(rightBat, rightBatSpeedY, Keyboard::Up, Keyboard::Down);


		//3 Отрисовка окна
		drawAll(game.window, leftBat, rightBat, ball, leftPlayerScoreText, rightPlayerScoreText);
		
	}
	return 0;
}