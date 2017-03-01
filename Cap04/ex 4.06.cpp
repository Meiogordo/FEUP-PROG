#include <iostream>
using namespace std;

void readIntArray(int a[], int nElem) {

	for (int i = 0; i < nElem; i++)
	{
		cout << "Insira o elemento " << i + 1 << " de " << nElem << ": ";
		cin >> a[i];
	}

}

int searchValueInIntArray(const int a[], int nElem, int value) {

	for (int i = 0; i < nElem; i++) {
		if (a[i] == value) {
			return i;
		}
	}

	return -1;
}

int searchMultValuesInIntArray(const int a[], int nElem, int value, int index[]) {

	int nValidElem = 0;

	for (int i = 0; i < nElem; i++) {
		if (a[i] == value) {
			index[nValidElem] = i;
			nValidElem++;
		}
	}

	return nValidElem;
}

int main() {

	int nElem;

	cout << "Insira o nr de elementos: ";
	cin >> nElem;

	int *a = new int[nElem]; // Mejic, du naught toush - Initializing array of unknown size using a variable for size

	readIntArray(a, nElem);

	cout << endl;

	for (int i = 0; i < nElem; i++) {
		cout << i << ": " << a[i] << endl;
	}

	int searchTerm;
	cout << "Insira o elemento a pesquisar: ";
	cin >> searchTerm;

	//cout << searchValueInIntArray(a, nElem, searchTerm) << endl;
	int *indexes = new int[nElem]; //Magic? Not again!
	int nelemsvalidos = searchMultValuesInIntArray(a, nElem, searchTerm, indexes);

	if (nelemsvalidos == 0)
		cout << "O elemento a pesquisar nao foi encontrado" << endl;
	else {
		cout << "Os elementos foram encontrados nos indices: ";
		for (int i = 0; i < nelemsvalidos;i++) {
			cout << indexes[i] << " ";
		}
		cout << endl;
	}



	return 0;
}