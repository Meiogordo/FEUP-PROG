
#include <iostream>
using namespace std;

int main() {

	int n[10];

	for (int i = 0; i < (sizeof(n) / sizeof(n[0])); i++) {
		cout << "Insira o numero " << i + 1 << " de " << (sizeof(n) / sizeof(n[0])) << endl;
		cin >> n[i];
	}

	cout << "\n\n";

	// bubble sort cos reasons - sort descendente

	bool flag = true;
	int lengthofarr = (sizeof(n) / sizeof(n[0]));
	while (flag && lengthofarr > 0) {

		lengthofarr--; // because the last element is already sorted
		flag = false;

		for (int i = 0; i < lengthofarr; i++) {
			if (n[i] < n[i + 1]) { // switch if bigger
				// cout << "vou trocar " << n[i] << " com " << n[i + 1] << endl; // debug
				int temp = n[i];
				n[i] = n[i + 1];
				n[i + 1] = temp;
				flag = true;
				// cout << "troquei " << n[i] << " com " << n[i + 1] << endl; // debug
			}
		}
	}

	for (int i = 0; i < (sizeof(n) / sizeof(n[0])); i++) {
		cout << "Numero " << i + 1 << " de " << (sizeof(n) / sizeof(n[0])) << ": " << n[i] << endl;
	}

	cout << endl << endl << "O maior numero e " << n[0] << endl;
	cout << "O menor numero e " << n[(sizeof(n) / sizeof(n[0])) - 1] << endl;

	return 0;
}