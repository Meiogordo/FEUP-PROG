#include <iostream>
#include <string>
using namespace std;

bool isHydroxide(char compound[]) {
	int length = 0;

	//getting length, sizeof cannot be trusted as it is inconsistent for some reason
	//using sizeof either I pushed it back too much by one for every test but the first or I only got the first one
	for (; compound[length] != '\0'; length++) {}

	if (compound[length - 2] == 'O' && compound[length - 1] == 'H')
		return true;
	else
		return false;
}

bool isHydroxide(string compound) {
	if (compound.substr(compound.size() - 2) == "OH")
		return true;
	else
		return false;
}

int main() {

	char test1[] = "KOH";
	char test2[] = "H2O2";
	char test3[] = "NaCl";
	char test4[] = "NaOH";
	char test5[] = "C9H8O4";
	char test6[] = "MgOH";

	string stest1 = "KOH";
	string stest2 = "H2O2";
	string stest3 = "NaCl";
	string stest4 = "NaOH";
	string stest5 = "C9H8O4";
	string stest6 = "MgOH";

	cout << "C strings:" << endl;
	cout << test1 << ": " << isHydroxide(test1) << endl;
	cout << test2 << ": " << isHydroxide(test2) << endl;
	cout << test3 << ": " << isHydroxide(test3) << endl;
	cout << test4 << ": " << isHydroxide(test4) << endl;
	cout << test5 << ": " << isHydroxide(test5) << endl;
	cout << test6 << ": " << isHydroxide(test6) << endl;

	cout << endl << "string strings:" << endl;
	cout << stest1 << ": " << isHydroxide(stest1) << endl;
	cout << stest2 << ": " << isHydroxide(stest2) << endl;
	cout << stest3 << ": " << isHydroxide(stest3) << endl;
	cout << stest4 << ": " << isHydroxide(stest4) << endl;
	cout << stest5 << ": " << isHydroxide(stest5) << endl;
	cout << stest6 << ": " << isHydroxide(stest6) << endl;

	return 0;
}