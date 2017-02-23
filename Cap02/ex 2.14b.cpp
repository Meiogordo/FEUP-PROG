#include <iostream>
using namespace std;

int main() {

	double delta;
	int nMaxIter;
	int n;
	double rq = 1, rqn;

	cout << "delta: ";
	cin >> delta;

	cout << "nMaxIter: ";
	cin >> nMaxIter;

	cout << "n: ";
	cin >> n;

	//determinar nr de casas decimais de delta
	double testdelta = delta;
	int ncasasdecimais = 0;

	for (; testdelta < 1; ncasasdecimais++) {
		testdelta *= 10;
	}

	//definir precis�o
	cout.precision(ncasasdecimais);
	cout << fixed;

	//primeira itera��o fora porque ainda n�o temos o valor de rqn
	rqn = (rq + n / rq) / 2;

	for (int i = 1; i < nMaxIter && abs(n - (rqn*rqn)) > delta; i++) {
		//i come�a a 1 pois a primeira itera��o foi feita fora
		rq = rqn; // rq toma o valor do rqn anterior
		rqn = (rq + n / rq) / 2;
	}

	cout << endl;
	cout << "O resultado e: " << rqn << endl;
	cout << "Valor obtido pelo sqrt de C: " << sqrt(n) << endl;
	cout << "Diferenca: " << (double)abs(rqn - sqrt(n)) << endl;

	return 0;
}