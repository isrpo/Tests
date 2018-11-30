#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

double function(double x) {
	return(cos(x));
}

void dichotomy_method(double a, double b, double eps) {
	int kol = 0;
	double x1, x2, y1, y2;
	while (abs(b - a) >= eps) {
		x1 = (a + b)/2 - eps/8;
		x2 = (a + b)/2 + eps/8;
		y1 = function(x1);
		kol++;
		y2 = function(x2); 
		kol++;
		//cout << a << " " << b << " " << abs(b - a) << " " << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
		if (y1 < y2) {
			b = x2;	
		}
		else {
			if (y1 == y2) {
				a = x1;
				b = x2;
			}
			else {
				a = x1;
			}
		}
	}
	cout << "Ответ: x = " << ((a + b) / 2) << endl;
	cout << "Количество вызовов функции f(x): " << kol << endl << endl;
}

void golden_method(double c, double d, double eps) {
	int kol = 0;
	double x1, x2, y1, y2;
	x1 = c + ((3 - sqrt(5)) / 2) * (d - c);
	x2 = c + ((sqrt(5) - 1) / 2) * (d - c);
	y1 = function(x1);
	kol++;
	y2 = function(x2);
	kol++;
	while (abs(d - c) >= eps) {
		//cout << c << " " << d << " " << abs(d - c) << " " << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
		if (y1 < y2) {
			d = x2;
			x2 = x1;
			x1 = c + ((3 - sqrt(5)) / 2) * (d - c);
			y2 = y1;
			y1 = function(x1);
			kol++;
		}
		else {
			c = x1;
			x1 = x2;
			x2 = c + ((sqrt(5) - 1) / 2) * (d - c);
			y1 = y2;
			y2 = function(x2);
			kol++;
		}
	}
	cout << "Ответ: x = " << ((c + d) / 2) << endl;
	cout << "Количество вызовов функции f(x): " << kol << endl << endl;
}

void fibonacci_method(double a, double b, double eps) {
	int n = 1, kol = 0;
	vector<int> feb;
	bool flag = true;
	double x1, x2, y1, y2, res = (b - a) / eps;
	feb.push_back(0);
	feb.push_back(1);
	feb.push_back(1);
	while (flag == true) {
		feb.push_back(feb[n + 1] + feb[n]);
		if (res < feb[n + 2]) {
			flag = false;
		}
		else {
			n++;
		}
	}
	x1 = a + ((double)feb[n] / feb[n + 2]) * (b - a);
	x2 = a + ((double)feb[n + 1] / feb[n + 2]) * (b - a);
	y1 = function(x1);
	kol++;
	y2 = function(x2);
	kol++;
	for (int k = 1; k <= n; k++) {
		//cout << a << " " << b << " " << abs(b - a) << " " << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
		if (y1 < y2) {
			b = x2;
			x2 = x1;
			x1 = a + ((double)feb[n - k + 1] / feb[n - k + 3]) * (b - a);
			y2 = y1;
			y1 = function(x1);
			kol++;
		}
		else {
			a = x1;
			x1 = x2;
			x2 = a + ((double)feb[n - k + 2] / feb[n - k + 3]) * (b - a);
			y1 = y2;
			y2 = function(x2);
			kol++;
		}
	}
	cout << "Ответ: x = " << ((a + b) / 2) << endl;
	cout << "Количество вызовов функции f(x): " << kol << endl << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << fixed;
	cout.precision(8);
	cout << "Метод дихотомии:" << endl;
	dichotomy_method(0, M_PI, 0.0001);
	cout << "Метод золотого сечения:" << endl;
	golden_method(0, M_PI, 0.0001);
	cout << "Метод Фибоначчи:" << endl;
	fibonacci_method(0, M_PI, 0.0001);
	return 0;
}