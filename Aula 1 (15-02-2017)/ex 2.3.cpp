#include <iostream>
using namespace std;

int main() {

	double op1, op2, result;
	char operation;

	cout << "Introduza o seu input no formato operando operacao operando." << endl;
	cin >> op1 >> operation >> op2;

	switch (operation) {

	case '+':
		result = op1 + op2;
		break;

	case '-':
		result = op1 - op2;
		break;

	case '/':
		result = op1 / op2;
		break;

	case '*':
		result = op1 * op2;
		break;

	default:
		cout << "Operacao invalida." << endl;
		return 1;
	}

	cout << "O resultado e: " << result << endl;

	return 0;
}