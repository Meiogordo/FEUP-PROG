#include <iostream>
#include <string>
using namespace std;

string normalizeName(string name) {
	//Trimming
	int firstnotspace = name.find_first_not_of(' ');
	name = name.substr(firstnotspace);
	int lastnotspace = name.find_last_not_of(' ');
	name = name.substr(0, lastnotspace + 1);

	//Making everything uppercase
	for (int i = 0; i < name.size(); i++) {
		name[i] = toupper(name[i]);
	}

	//Removing particles
	string toRemove[] = { "DAS", "DOS", "DE", "DO", "DA", "E" };

	for (int j = 0; j < (sizeof(toRemove) / sizeof(toRemove[0])); j++) {

		while (name.find(toRemove[j]) != -1) {
			name = name.substr(0, name.find(toRemove[j])) + name.substr(name.find(toRemove[j]) + toRemove[j].size());
		}
	}

	//Removing double spaces
	for (int i = 0; i < name.size(); i++) {
		if (name[i] == ' ' && name[i + 1] == ' ') {
			int firstnonspace = name.substr(i).find_first_not_of(' '); //first non space char from i to the end of the string
			name = name.substr(0, i + 1) + name.substr(firstnonspace + i);
			// from start of string until found space (the second argument is non inclusive so we have to use i + 1 to include the space at i
			// then we append that with the substr from the first non space char - +i because we measured it from i onwards, so we have to add i
		}
	}

	return name;
}

int main() {
	string input = "    Asdrubal           hipolito    das    banheiras     e dos polibas      ";
	cout << input << endl;
	cout << normalizeName(input) << "." << endl; //The dot is there to test if the trailing whitespace was removed

	return 0;
}