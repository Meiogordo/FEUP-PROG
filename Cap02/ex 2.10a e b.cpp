#include <iostream>
#include <math.h>
using namespace std;

bool isCapicua(int);
int msd(int);
int lsd(int);
int sizeofInt(int);

//determina se um número é capicua, true se for, false se não for
bool isCapicua(int input) {

	while (input > 0) {
		if (msd(input) == lsd(input)) {
			input = input % (int)pow(10, (sizeofInt(input) - 1));
			input /= 10;
		}
		else return false;
	}

	return true;
}

// retorna o dígito mais significativo
int msd(int input) {

	input /= (int)pow(10, sizeofInt(input) - 1);

	return input;
}

// retorna o dígito menos significativo
int lsd(int input) {

	return input % 10;
}

int sizeofInt(int input) {
	int size = 0;

	while (input > 0) {
		input /= 10;
		size++;
	}

	return size;
}

int main() {

	int input;

	cout << "numero? ";
	cin >> input;

	bool teste = isCapicua(input);

	cout << "O numero " << input << (teste ? " e capicua" : " nao e capicua") << endl;

	return 0;
}