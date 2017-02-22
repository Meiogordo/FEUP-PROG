
#include <iostream>
using namespace std;

int main() {

	int minnr = 9999999; //nr minimo - inicializar muito grande para ficar logo o primeiro como menor
	int maxnr = -99999999; //nr maximo - inicializar muito pequeno para ficar logo o primeiro como maior
	int input; //buffer de input
	int soma = 0, nrelementos = 0; //soma e nr de elementos
	double media; //para guardar a media final

	do {
		cout << "Insira o elemento nr " << nrelementos + 1 << ": ";
		cin >> input;

		if (input != 0) {
			soma += input;
			nrelementos++;
			if (input > maxnr)
				maxnr = input;
			if (input < minnr)
				minnr = input;
		}
		else {
			cout << "Foi detetado um zero, terminando a recolha de informacao..." << endl;
		}

	} while (input != 0);

	media = (double)soma / nrelementos;
	
	cout << endl;

	cout << "O maior numero da sequencia e: " << maxnr << endl;
	cout << "O menor numero da sequencia e: " << minnr << endl;
	cout << "A soma dos elementos e: " << soma << endl;
	cout << "A media dos elementos e: " << media << endl;



	return 0;
}