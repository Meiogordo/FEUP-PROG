#include <iostream>
using namespace std;

// returns the number of decimal places that the passed float/double has
int decimalPlacesCounter(double n) {

	int ncasasdecimais = 0;

	for (; n < 1; ncasasdecimais++) {
		n *= 10;
	}

	return ncasasdecimais;
}

//calculates the square root via the Heron method
//where n is the value to calculate the square root of, delta is the max amount of decimal places
//and nMaxIter is the maximum number of iterations (for code safety)
double newSqrtMethod(int n, double delta, int nMaxIter) {
	//sr - square root, nsr - new square root, because iterations are based on one another
	double sr = 1, nsr;

	//first iteration is done outside because nsr has not been set yet
	nsr = (sr + n / sr) / 2;

	for (int i = 1; i < nMaxIter && abs(n - (nsr*nsr)) > delta; i++) {
		//i starts at one because the first iteration was done outside
		sr = nsr; // sr takes in the value of the last nsr
		nsr = (sr + n / sr) / 2;
	}

	return nsr;
}

int main() {

	double delta;
	int nMaxIter;
	int n;
	double result;

	cout << "delta: ";
	cin >> delta;

	cout << "nMaxIter: ";
	cin >> nMaxIter;

	cout << "n: ";
	cin >> n;

	//determinar nr de casas decimais de delta
	int ncasasdecimais = decimalPlacesCounter(delta);

	//definir precisão
	cout.precision(ncasasdecimais);
	cout << fixed;

	result = newSqrtMethod(n, delta, nMaxIter);

	cout << endl;
	cout << "O resultado e: " << result << endl;
	cout << "Valor obtido pelo sqrt de C: " << sqrt(n) << endl;
	cout << "Diferenca: " << (double)abs(result - sqrt(n)) << endl;

	return 0;
}