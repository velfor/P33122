#include "settings.h"
#include "functions.h"
#include "game.h"
using namespace sf;

int main()
{
	srand(time(nullptr));
	/*
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);*/
	Game game;
	game.window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	game.window.setFramerateLimit(FPS);
	//�������� �������� ����
	//�������
	RectangleShape leftBat, rightBat;
	initBat(game.leftBat, leftBatColor, leftBatStartPos);
	initBat(game.rightBat, rightBatColor, rightBatStartPos);
	

	//�����
	CircleShape ball;
	initBall(ball, ballColor, ballStartPosition);
	float arr_speed[]{ -5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f };
	int index = rand() % 10;
	float ball_speedx = arr_speed[index];
	index = rand() % 10;
	float ball_speedy = arr_speed[index];

	//����
	int leftPlayerScore = 0;
	int rightPlayerScore = 0;
	
	//�����
	Font font;
	font.loadFromFile("ds-digib.ttf");
	//������ ��� �����
	Text leftPlayerScoreText;
	initText(leftPlayerScoreText, leftPlayerScore, font, charSize, leftTextStartPos);

	Text rightPlayerScoreText;
	initText(rightPlayerScoreText, rightPlayerScore, font, charSize, rightTextStartPos);
	
	// ������� ���� ����������. �����������, ���� ������� ����
	while (game.window.isOpen())
	{
		//1 ������������ ������� ������� � �����
		Event event;
		while (game.window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				game.window.close();
		}

		//2 ���������� ��������
		//�����
		//�������� ������
		ball.move(ball_speedx, ball_speedy);
		//�����-����� �� ����� 
		if (ball.getPosition().x <= 0)
			ballReboundX(ball_speedx, rightPlayerScore,
				rightPlayerScoreText);

		//��� ������ �������
		if (ball.getPosition().x >=(WINDOW_WIDTH - 2 * ballRadius))
			ballReboundX(ball_speedx, leftPlayerScore,
				leftPlayerScoreText);
		//������� ��� ������ �������
		if (ball.getPosition().y <= 0 || ball.getPosition().y >=
			(WINDOW_HEIGHT - 2 * ballRadius))
			ball_speedy = -ball_speedy;

		controlBat(leftBat, leftBatSpeedY, Keyboard::W, Keyboard::S);
		controlBat(rightBat, rightBatSpeedY, Keyboard::Up, Keyboard::Down);


		//3 ��������� ����
		drawAll(game.window, leftBat, rightBat, ball, leftPlayerScoreText, rightPlayerScoreText);
		
	}
	return 0;
}