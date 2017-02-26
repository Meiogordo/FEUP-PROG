#include <iostream>
#include <string>
using namespace std;

void decompose(string compound) {

	int startofElement = 0;

	for (int i = 0; i < compound.size(); i++)
	{
		if (isupper(compound[i])) //if it is upper case, it is the start of a new element or a size 1 element, so new line and then print char
			cout << endl << compound[i];
		else if (!isdigit(compound[i])) //if it is lower case (else of upper case) and not a digit, just print it in the same line
			cout << compound[i];
	}

	cout << endl;
}


int main() {

	string compounds[] = { "H2O", "KOH", "H2O2", "NaCl", "NaOH", "C9H8O4", "MgOH" };

	for (int i = 0; i < (sizeof(compounds) / sizeof(compounds[0])); i++) {
		cout << compounds[i] << " is constituted by:" << endl;
		decompose(compounds[i]);
		cout << endl;
	}


	return 0;
}