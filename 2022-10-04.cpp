#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL,"rus");
	/*Case1.Дано целое число в диапазоне 1–7.Вывести строку —
	название дня недели, соответствующее данному числу(1 —
	«понедельник», 2 — «вторник» и т.д.).*/
	/*
	int day;
	cin >> day;
	if (day == 1) {
		cout << "понедельник" << endl;
	}
	else if (day == 2) {
		cout << "вторник" << endl;
	}
	//пропущено несколько else-if
	else if (day == 7) {
		cout << "воскресенье" << endl;
	}
	else {
		cout << "Ошибочный номер дня" << endl;
	}
	*/
	/*int day;
	cin >> day;
	switch (day) {
		case 1: cout << "понедельник" << endl; break;
		case 2: cout << "вторник" << endl; break;
		case 3: cout << "среда" << endl; break;
		case 4: cout << "четверг" << endl; break;
		case 5: cout << "пятница" << endl; break;
		case 6: cout << "суббота" << endl; break;
		case 7: cout << "воскресенье" << endl; break;
		default: cout << "Ошибочный номер дня" << endl;
	}
	*/

	/*Case2.Дано целое число K.Вывести строку - описание оценки,
	соответствующей числу K(1 — «плохо», 2 —«неудовлетворительно»,
	3 — «удовлетворительно», 4 — «хорошо», 5 — «отлично»).
	Если K не лежит в диапазоне 1–5, то вывести строку «ошибка».*/

	/*int mark;
	cin >> mark;
	switch (mark) {
		case 1: cout << "плохо" << endl; break;
		case 2: cout << "неудовлетворительно" << endl; break;
		case 3: cout << "удовлетворительно" << endl; break;
		case 4: cout << "хорошо" << endl; break;
		case 5: cout << "отлично" << endl; break;
		default: cout << "ошибка" << endl;
	}*/
	/*Case3.Дан номер месяца — целое число в диапазоне 1–12(1 — январь, 2 — февраль и т.д.).Вывести название соответствующего времени года(«зима»,
		«весна», «лето», «осень»).*/
	/*int month;
	cin >> month;
	switch (month) {
		case 1:
		case 2:
		case 12: cout << "зима" << endl; break;
		case 3:
		case 4:
		case 5: cout << "весна" << endl; break;
		case 6:
		case 7:
		case 8: cout << "лето" << endl; break;
		case 9:
		case 10:
		case 11: cout << "осень" << endl; break;
	}*/

	return 0;
}