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

	cout << "A solução é: " << endl;

	cout << "x = " << (c*e - b*f) / (a*e - b*d) << endl;
	cout << "y = " << (a*f - c*d) / (a*e - b*d) << endl;

	return 0;
}