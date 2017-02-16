#include <iostream>
using namespace std;

int main() {

	double a, b, c, d, e, f;

	cout << "eq 1: a*x + b*y = c" << endl;
	cout << "Introduza os valores de a, b e c, respetivamente." << endl;
	cin >> a >> b >> c;

	cout << "eq 2: d*x + e*y = f" << endl;
	cout << "Introduza os valores de d, e e f, respetivamente." << endl;
	cin >> d >> e >> f;

	//Determinar se o sistema é indeterminado (se um dos numeradores for zero)
	if ((c*e - b*f) == 0.0 || (a*f - c*d) == 0.0) {
		cout << "\nSistema Indeterminado.\n\n";
		return 1;
	}

	//Determinar se o sistema é impossível (se um dos denominador for zero)
	if ((a*e - b*d) == 0.0) {
		cout << "\nSistema Impossivel.\n\n";
		return 1;
	}

	cout << "A solucao e: " << endl;

	cout << "x = " << (c*e - b*f) / (a*e - b*d) << endl;
	cout << "y = " << (a*f - c*d) / (a*e - b*d) << endl;

	return 0;
}