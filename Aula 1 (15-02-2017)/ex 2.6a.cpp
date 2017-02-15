#include <iostream>
using namespace std;

int main() {

	//Testa um nr para ver se é primo

	int n = 0;
	bool isprime = true;

	cout << "Insira o numero a testar: ";
	cin >> n;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			isprime = false;
			break;
		}
	}

	cout << "O numero inserido " << (isprime ? "e primo." : "nao e primo.") << endl;

	return 0;
}