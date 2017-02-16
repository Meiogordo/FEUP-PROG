#include <iostream>
using namespace std;

int main() {

	cout.precision(3);
	cout << fixed;

	double a, b, c;

	cout << "Introduza os coeficientes para uma equacao do tipo ax^2 + bx + c = 0\n(a b c): ";
	cin >> a >> b >> c;

	double delta = b*b - 4*a*c;

	if (delta > 0) {
		cout << "A equacao tem 2 raizes reais diferentes: " << (-b + sqrt(delta)) / (2 * a) << " e " << (-b - sqrt(delta)) / (2 * a) << endl;
	} else if (delta == 0) {
		cout << "A equacao tem 2 raizes reais iguais: " << (-b + sqrt(delta)) / (2 * a) << endl;
	} else {
		cout << "A equacao tem 2 raizes complexas conjugadas: " << -b / (2 * a) << "+" << sqrt(abs(delta)) / (2 * a) << "i" << " e " << -b / (2 * a) << "-" << sqrt(abs(delta)) / (2 * a) << "i" << endl;
	}

	return 0;
}