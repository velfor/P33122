#include <iostream>
using namespace std;
/*
������� ����� ������. 2 ���� - ��� � ����. 6+ ������� - ������������, ������� � �������.
������� 1-� ������ ������������� ��� ����������, 2- - �������������� � �����������.
���������� �����-�� �������� � 1-� ������ � ������� ��������. ������� ������ �� �����.
*/
class Banana {
private:
	string color;
public:
	Banana() { color = "green";	}
	Banana(string fcolor) {	color = fcolor;	}
	string getColor() { return color; }
	void setColor(string fcolor) { color = fcolor; }
};

class Apple {
private:
	size_t weight;
	string type;
public:
	Apple() {
		weight = 0;
		type = "";
	}
	Apple(size_t fweight, string ftype) {
		weight = fweight;
		type = ftype;
	}
	size_t getWeight() { return weight; }
	string getType() { return type; }
	void setWeight(size_t fweight) { weight = fweight; }
	void setType(string ftype) { type = ftype; }
};

int main() {
	/*Banana b1;
	cout << b1.getColor()<< endl;
	b1.setColor("yellow");
	cout << b1.getColor() << endl;
	Banana b2("black");
	cout << b2.getColor() << endl;*/
	Apple a1;
	cout << a1.getType() << " " << a1.getWeight() << endl;
	a1.setType("pepin");
	a1.setWeight(100);
	cout << a1.getType() << " " << a1.getWeight() << endl;

	Apple a2(250, "jonatan");
	cout << a2.getType() << " " << a2.getWeight() << endl;
	return 0;
}