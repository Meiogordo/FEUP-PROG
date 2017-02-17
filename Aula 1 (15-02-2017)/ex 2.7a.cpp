#define _USE_MATH_DEFINES

#include <iostream>
using namespace std;

int main() {

	cout.precision(6);
	cout << fixed;

	cout << "ang\tsen\t\tcos\t\ttan" << endl;

	// i esta em graus, as funcoes trigonometricas usam radianos
	for (int i = 0; i <= 90; i += 15) {
		if(i == 90)
			cout << i << "\t" << sin(i*M_PI / 180) << "\t" << cos(i*M_PI / 180) << "\t" << "infinito" << endl;
		else
			cout << i << "\t" << sin(i*M_PI / 180) << "\t" << cos(i*M_PI / 180) << "\t" << tan(i*M_PI / 180) << endl;
	}

	return 0;
}