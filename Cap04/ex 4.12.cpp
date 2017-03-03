#include <iostream>
#include <string>
using namespace std;

//Removes prefixing and sufixing spaces from the input string.
void trimString(string &str) {
	str.erase(0, str.find_first_not_of(' '));
	str.erase(str.find_last_not_of(' ') + 1);
}

//Testing with documentation, ignore
///@brief Reads an operation from a string in the format num1 op num2
///@param op The string representing the operation.
///@return The result of the operation
double executeOperation(string op) {

	string snum1, soperation, snum2;
	char operation;
	double num1, num2;
	double result = 0;
	for (int i = 0; i < op.size() && (op[i] == '.' || isdigit(op[i])); i++) {
		snum1.push_back(op[i]);
	}

	//cout << "num1: " << num1 << "." << endl;

	op = op.substr(snum1.size());

	//cout << "newop:" << op << "," << endl;

	for (int i = 0 + 1; i < op.size() && !isdigit(op[i]); i++) {
		soperation.push_back(op[i]);
	}

	op = op.substr(soperation.size());

	/*cout << "operation:" << operation << "'" << endl;
	cout << "newop:" << op << "," << endl;*/

	snum2 = op;

	//trims
	trimString(snum1);
	trimString(snum2);
	trimString(soperation);

	num1 = stof(snum1);
	num2 = stof(snum2);
	operation = soperation[0];

	switch (operation) {
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		result = num1 / num2;
		break;
	default:
		cout << "Error!" << endl;
		result = 0.00000000000000001;
		break;
	}

	return result;
}

int main() {

	string op1;
	cout << "Insert an operation in the following format: num1 op num2\n";
	//using getline because the regular cin would only get the first element, because cin splits the input when there is a space
	getline(cin, op1);
	cout << "The result is: " << executeOperation(op1) << endl;

	//Test in pdf
	//cout << executeOperation("12.3 + 5") << endl;

	//Testing trimString
	/*string str;
	str = "   1  2 + + + +       ";
	cout << "//" << str << "//" << endl;
	trimString(str);
	cout << "//" << str << "//" << endl;*/

	return 0;
}