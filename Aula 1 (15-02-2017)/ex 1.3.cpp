
#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
using namespace std;

int main() {

	//#desisti
	long double M;
	double p, r;

	cout << "Qual a massa espec�fica do material de que a esfera � feita? (Kg / m^3)" << endl;
	cin >> p;

	cout << "Qual o raio da esfera? (m)" << endl;
	cin >> r;

	M = (long double)(4 / 3) * p * M_PI * (r * r * r);

	cout << "O valor de massa da esfera, em Kg, � " << M << endl;

	return 0;
}