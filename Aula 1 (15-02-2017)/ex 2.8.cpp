#include <iostream>
using namespace std;

int main() {

	int nanos;
	double percjuros, qinicial, qfinal;

	cout << "Numero de anos? ";
	cin >> nanos;
	cout << "Percentagem juros? ";
	cin >> percjuros;
	cout << "Quantia inicial? ";
	cin >> qinicial;

	qfinal = qinicial;

	for (int anos = 1; anos <= nanos; anos++, qfinal *= 1 + (percjuros/100)) {}

	cout << "A quantia final e de " << qfinal << " euros." << endl;

	return 0;
}