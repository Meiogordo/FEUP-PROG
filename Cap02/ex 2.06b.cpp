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

	//Escreve os primeiros 100 primos

	for (int progresso = 0, i = 2; progresso < 100; i++) {
		
		if (isprime(i)) {
			cout << i << "\t";
			progresso++;
		}
		
	}

	return 0;
}