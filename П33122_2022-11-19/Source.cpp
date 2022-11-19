#include <iostream>
using namespace std;
int sign(double x) {
	if (x < 0) return -1;
	if (x == 0) return 0;
	if (x > 0) return 1;
}
int rootsCount(double a, double b, double c) {
	double d = b * b - 4 * a * c;
	/*
	если D > 0, 2 корня
	если D = 0, 1 корень
	если D < 0, 0 корней
	*/
	if (d > 0) return 2;
	if (d == 0) return 1;
	if (d < 0) return 0;
}
int main() {
/*
Proc16. Описать функцию sign(X) целого типа, возвращающую для вещественного числа X следующие значения:
	−1, если X < 0; 
	0, если X = 0; 
	1, если X > 0.
С помощью этой функции найти значение выражения 
sign(A) + sign(B)
для данных вещественных чисел A и B.
*/
	/*double a, b;
	cin >> a >> b;
	cout << sign(a) + sign(b) << endl;*/
/*Proc17.Описать функцию rootsCount(A, B, C) целого типа, определяющую количество корней квадратного уравнения 
A·x^2 + B·x + C = 0 (A, B, C — вещественные параметры, A не равно 0).С ее помощью найти количество корней		для каждого из трех квадратных уравнений с данными коэффициентами. Количество корней определять по значению дискриминанта : D = B^2 − 4·A·C.
если D > 0, 2 корня
если D = 0, 1 корень
если D < 0, 0 корней
*/
	double a, b, c;
	cin >> a >> b >> c;
	cout << rootsCount(a, b, c) << endl;



	//for (int i = 0; i < n; i++)
	return 0;
}