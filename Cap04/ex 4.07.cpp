#include <iostream>
#include <vector>
using namespace std;

void readIntVector(vector<int> &v) {
	int temp;

	while (1) {
		cout << "Insira o elemento nr " << v.size() + 1 << " (ctrl+z para terminar): ";
		cin >> temp;
		if (cin.eof()) {
			cin.clear();
			break;
		}
		else {
			v.push_back(temp);
		}
	}
}
vector<int> readIntVector() {
	int temp;
	vector<int> v;

	while (1) {
		cout << "Insira o elemento nr " << v.size() + 1 << " (ctrl+z para terminar): ";
		cin >> temp;
		if (cin.eof()) {
			cin.clear();
			break;
		}
		else {
			v.push_back(temp);
		}
	}

	return v;
}

void readIntVector(vector<int> &v, int nElem) {
	int temp;

	for (int i = 0; i < nElem; i++) {
		cout << "Insira o elemento " << i + 1 << " de " << nElem << ": ";
		cin >> temp;
		v.push_back(temp); //Esparguete, TODO: Não esparguete
	}

}

int searchValueInVector(const vector<int> &v, int value) {

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == value) {
			return i;
		}
	}

	return -1;
}

vector<int> searchMultValuesInIntVector(const vector<int> &v, int value) {

	vector<int> results;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == value) {
			results.push_back(i);
		}
	}

	return results;
}

int main() {

	int nElem;

	cout << "Insira o nr de elementos: ";
	cin >> nElem;

	vector <int> v; // no more magic
	v.reserve(nElem);

	readIntVector(v, nElem);

	cout << endl;

	for (int i = 0; i < nElem; i++) {
		cout << i << ": " << v[i] << endl;
	}

	int searchTerm;
	cout << "Insira o elemento a pesquisar: ";
	cin >> searchTerm;

	//cout << searchValueInIntArray(a, nElem, searchTerm) << endl;
	vector<int> encontrados = searchMultValuesInIntVector(v, searchTerm); //No more no more

	if (encontrados.size() == 0)
		cout << "O elemento a pesquisar nao foi encontrado" << endl;
	else {
		cout << "Os elementos foram encontrados nos indices: ";
		for (int i = 0; i < encontrados.size();i++) {
			cout << encontrados[i] << " ";
		}
		cout << endl;
	}



	return 0;
}