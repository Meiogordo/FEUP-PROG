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

	//primeira iteração fora porque ainda não temos o valor de rqn
	rqn = (rq + n / rq) / 2;

	for (int i = 1; i < nMaxIter && abs(n - (rqn*rqn)) > delta; i++) {
		//i começa a 1 pois a primeira iteração foi feita fora
		rq = rqn; // rq toma o valor do rqn anterior
		rqn = (rq + n / rq) / 2;
	}

	cout << endl;
	cout << "O resultado e: " << rqn << endl;

	return 0;
}