#include <iostream>
#include <vector>
using namespace std;

//protos
bool isprime(int n);
void getPrimesToN(int nmax, vector<int> &primes);

bool isprime(int n) {

	//Testa um nr para ver se é primo
	bool test = true;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			test = false;
			break;
		}
	}

	return test;
}

//Gera os primos abaixo de n
void getPrimesToN(int nmax, vector<int> &primes) {
	for (int i = 2; i < nmax; i++) {
		if (isprime(i))
			primes.push_back(i);
	}
}

int main() {

	int n;
	vector <int> primesUntilN;
	vector <int> primesUsed;

	cout << "Insira o seu numero aqui: ";
	cin >> n;

	if (isprime(n)) {
		cout << n << " e primo e portanto nao pode ser decomposto em fatores primos." << endl;
	}
	else {

		int preservaN = n;

		bool wasDivided = false;

		getPrimesToN(n, primesUntilN);

		while (n > 1) {
			wasDivided = false;

			for (int j = 0; j < primesUntilN.size(); j++) {
				if (n % primesUntilN[j] == 0) {
					wasDivided = true;
					n /= primesUntilN[j];
					primesUsed.push_back(primesUntilN[j]);
					break;
				}
			}
		}

		//Test to see if the primes were generated correctly
		/*cout << "Primos ate n: " << endl;

		for (int i = 0; i < primesUntilN.size(); i++) {
			cout << primesUntilN[i] << endl;
		}*/

		cout << "\n" << preservaN << " = ";

		cout << primesUsed[0];

		for (int i = 1; i < primesUsed.size(); i++) {
			cout << "*" << primesUsed[i];
		}

		cout << endl;

	}

	return 0;
}