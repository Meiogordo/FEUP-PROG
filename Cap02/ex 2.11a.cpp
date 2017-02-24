#include <iostream>
using namespace std;

int main() {

	cout.precision(13);
	cout << fixed;

	int ntermos = 0;
	long double val = 0;

	cout << "N termos a calcular? ";
	cin >> ntermos;

	for (int i = 0; i < ntermos; i++) {
		if (i % 2 == 0)
			val += (double)4 / (2 * i + 1);
		else
			val -= (double)4 / (2 * i + 1);
	}

	cout << "O resultado final e " << val << endl;

	return 0;
}