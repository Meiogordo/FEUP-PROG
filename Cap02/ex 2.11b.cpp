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
	long double val = 0;

	cout << "N termos a calcular? ";
	cin >> ntermos;

	for (int i = 0; i < ntermos; i++) {
		val += (long double) 1 / factorial(i);
	}

	cout << "O resultado final e " << val << endl;

	return 0;
}