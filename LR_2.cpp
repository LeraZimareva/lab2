//Лабораторная работа № 2
//Вариант 6. Создать класс «Время» с полями : часы(0−23), минуты(0−59), секунды (0−59). В классе реализовать функции конструктора, деструктора, 
//установки времени, получения часа, минуты и секунды, а также две функции - члены печати : печать по шаблону «16 часов 18 минут 3 секунды» и 
//«4 : 18 : 3 p.m.». Функции - члены установки полей класса должны проверять корректность задаваемых параметров.

// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <stdio.h>
#include <iostream>

using namespace std;

class CTime {

	int tempSec = 0, tempMin = 0, tempHour = 0; //поля сек, мин и часы
public:
	//конструктор по умолчанию
	CTime() {
	}

	//конструктор, параметрами которого являются заданные значения часов, минут и секунд;
	CTime(int h, int m, int s) {
		//проверка на корректность ввода в конструкторе 
		if (h > 23 || h < 0 || m>59 || m < 0 || s>59 || s < 0)

		{
			cout << "Ошибка! Введены некорректные данные. Повторите ввод.";
		}
		else
		{
			tempHour = h;
			tempMin = m;
			tempSec = s;
		}
	}

	//конструктор копирования
	CTime(CTime& c) {
		tempSec = c.tempSec;
		tempHour = c.tempHour;
		tempMin = c.tempMin;
	}

	//вывод времени
	void getTime() {
		cout << getHour() << " часов " << getMin() << " минут " << getSec() << " секунды " << endl;
	}

	void getAmer() {
		if (getHour() > 12) { cout << getHour() - 12 << ":" << getMin() << ":" << getSec() << " p.m."; }
		else if (getHour() < 12) { cout << getHour() << ":" << getMin() << ":" << getSec() << " a.m."; }
		cout << endl;
	}

	//свойства
	int getHour() {
		return tempHour;
	}
	int getMin() {
		return tempMin;
	}
	int getSec() {
		return tempSec;
	}

	void setHour(int h) {
		if (h >= 0 && h <= 23) tempHour = h;
	}
	void setMin(int m) {
		if (m >= 0 && m <= 59) tempMin = m;
	}
	void setSec(int s) {
		if (s >= 0 && s <= 59) tempSec = s;
	}

	//методы - функции для задания значения поля класса CTime и получения часов, минут и 
	//секунд по заданному значению типа CTime
	void setTime(int h, int m, int s) {
		if (h > 23 || h < 0 || m>59 || m < 0 || s>59 || s < 0)
		{
			cout << "Ошибка! Введите еще раз.";
		}
		else {
			setHour(h);
			setMin(m);
			setSec(s);
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите часы" << endl;
	int h, m, s;
	cin >> h;
	cout << "Введите минуты" << endl;
	cin >> m;
	cout <<"Введите секунды" << endl;
	cin >> s;
	CTime time(h, m, s);
	cout << "Вывод времени на экран в общепринятом формате «часов минут секунд»\n";
	time.getTime();
	cout << endl;
	cout << "Вывод времени на экран в  виде «чч : мм : cc p.m.»\n";
	time.getAmer();
	cout << endl;
}