#include <iostream>
#include <string>
#include <vector>
using namespace std;

void bubblesort(vector<string> &v) {

	bool flag = true;
	int lengthofarr = v.size();
	int comparison;

	while (flag && lengthofarr > 0) {

		lengthofarr--; // because the last element is already sorted
		flag = false;

		for (int i = 0; i < lengthofarr; i++) {
			comparison = v[i].compare(v[i + 1]); // compare returns 0 if equal, <0 if compared string (v[i+1]) is smaller or >0 if compared string is bigger
			// (Actually either the value of the first character that does not match is lower or all compared characters match but the compared string is shorter.) - correct explanation
			if (comparison > 0) { // switch if bigger
				swap(v[i], v[i + 1]);
				flag = true;
			}
		}
	}

}

int main() {

	vector<string> input;
	string temp;

	//Input - thanks to Rui for the algorithm, in the one I used I had to delete the last duplicated item, which made for some good spaghetti
	cout << "Insira as strings desejadas (ctrl+z para terminar)" << endl;
	while (1) {
		cout << "String nr " << input.size() + 1 << ": ";
		cin >> temp;
		if (cin.eof()) {
			cin.clear();
			break;
		}
		input.push_back(temp);
	}

	cout << "\n\n";

	//Sorting
	bubblesort(input);

	cout << "Sorted strings:\n";
	//Display
	for (int i = 0; i < input.size(); i++) {
		cout << input[i] << endl;
	}

	return 0;
}