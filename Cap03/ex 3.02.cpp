#include <iostream>
using namespace std;

//Testa um nr para ver se é primo
bool isPrime(int n) {

	bool test = true;

	//nice try, pizza guy!
	if (n == 1)
		return false;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			test = false;
			break;
		}
	}
	return test;
}

int main() {

	int n;

	cout << "Insira o nr a testar: ";
	cin >> n;

	cout << n << (isPrime(n) ? " e primo." : " nao e primo.") << endl;

	return 0;
}