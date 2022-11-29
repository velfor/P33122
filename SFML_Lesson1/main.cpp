#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;
const float SC_WIDTH = 800.f;
const float SC_HEIGHT = 600.f;
int main()
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(SC_WIDTH, SC_HEIGHT), "SFML Works!");
	
	float radius = 200.f;
	CircleShape c1(radius);
	c1.move((SC_WIDTH - 2*radius)/2, (SC_HEIGHT - 2*radius)/2);
	c1.setFillColor(Color{200,100,50});

	srand(time(0));
	const int size = 5;
	CircleShape arr_circle[size];
	for (int i = 0; i < size; i++) {
		radius = 200.f - 40*i;
		arr_circle[i].setRadius(radius);
		arr_circle[i].move((SC_WIDTH - 2 * radius) / 2, (SC_HEIGHT - 2 * radius) / 2);
		arr_circle[i].setFillColor(Color{(Uint8)(50*i), (Uint8)(rand() % 256) , (Uint8)(rand() % 256) });
	}

	float dx = 100.f;
	RectangleShape arr_rect[size];
	for (int i = 0; i < size; i++) {
		arr_rect[i].setSize(Vector2f(50.f,50.f));
		arr_rect[i].move(dx * i, 0);
		arr_rect[i].setFillColor(Color{ (Uint8)(50 * i), (Uint8)(rand() % 256) , (Uint8)(rand() % 256) });
	}
	
	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		//1 ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		//2 ���������� ��������
		
		//3 ��������� �������� � ���������� ����
		window.clear();
		for (int i = 0; i < size; i++) {
			window.draw(arr_circle[i]);
			window.draw(arr_rect[i]);
		}
		window.display();
	}

	return 0;
}