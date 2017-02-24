#include <iostream>
using namespace std;

long long int factorial(int in) {
	long long int out = 1;
	while (in > 1) {
		out *= in;
		in--;
	}
	return out;
}

int main() {

	cout.precision(64);
	cout << fixed;

	int ntermos = 0;
	int xinit = 0;
	long double val = 1;

	cout << "N termos a calcular? ";
	cin >> ntermos;

	cout << "Valor de x? ";
	cin >> xinit;

	for (int i = 1; i < ntermos; i++) {
		if (i % 2 == 0)
			val += (long double)pow(xinit, i) / factorial(i);
		else
			val -= (long double)pow(xinit, i) / factorial(i);
	}

	cout << "O resultado final e " << val << endl;

	return 0;
}