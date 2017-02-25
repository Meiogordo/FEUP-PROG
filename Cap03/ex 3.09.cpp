#include <iostream>
#include <climits>
using namespace std;

//g(x) function
double gx(double n) {
	return pow(n, 2);
}

//h(x) function
double hx(double n) {
	return sqrt(4 - pow(n, 2));
}

double integrateTR(double f(double), double a, double b, int n) {
	double h = (b - a) / n;
	double result = 0;

	for (int i = 1; i <= n; i++) {
		result += (h / 2) * (f(a + (i - 1) * h) + f(a + i*h));
	}

	return result;
}

int main() {

	int n = 2; //2, 4, 8, 16, 32, 64, 128 - bigger n means smaller h and better precision
	int ag = 0, bg = 10;

	cout << "g(x): " << endl;
	for (n = 2; n <= 128; n *= 2) {
		cout << integrateTR(gx, ag, bg, n) << endl;
	}

	int ah = -2, bh = 2;

	cout << "h(x): " << endl;
	for (n = 2; n <= 128; n *= 2) {
		cout << integrateTR(hx, ah, bh, n) << endl;
	}

	return 0;
}