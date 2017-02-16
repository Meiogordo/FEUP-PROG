#include <iostream>
using namespace std;

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

int main() {

	//Escreve os primos abaixo de 10000

	for (int i = 2; i < 10000; i++) {

		if (isprime(i))
			cout << i << "\t";
		
	}

	cout << endl;

	return 0;
}