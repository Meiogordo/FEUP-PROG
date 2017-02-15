
#include <iostream>
using namespace std;

int main() {

	double n[3];

	for (int i = 0; i < (sizeof(n) / sizeof(n[0])); i++) {
		cout << "Insira o lado " << i + 1 << " de " << (sizeof(n) / sizeof(n[0])) << endl;
		cin >> n[i];
	}

	cout << "\n";

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

	/*for (int i = 0; i < (sizeof(n) / sizeof(n[0])); i++) {
		cout << "Numero " << i + 1 << " de " << (sizeof(n) / sizeof(n[0])) << ": " << n[i] << endl;
	}*/

	if (n[1] + n[2] < n[0])
		cout << "Nao e possivel construir o triangulo.\n";
	else
		cout << "E possivel construir o triangulo.\n";


	return 0;
}