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

void removeDuplicates(vector<string> &v) {
	//removes duplicates from a vector.
	//The resizing part is much much easier using vector.erase but I wanted to try to use .resize like the exercise said.
	vector <string> seen;
	bool isinseen = false;

	for (int i = 0; i < v.size(); i++) {
		isinseen = false;
		for (int j = 0; j < seen.size(); j++) {
			if (v[i] == seen[j]) {
				isinseen = true;
				break;
			}
		}

		if (isinseen) {
			//duplicated element - move back the trailing elements and resize the vector
			for (int z = i + 1; z < v.size(); z++) {
				v[z - 1] = v[z];
			}
			v.resize(v.size() - 1);
			i--; // resize makes indexes switch up, have to go back one step
			//basically if at i we pull everything back by 1 and then go to i+1, we will be really going to i+2 in relation to the old vector
		}
		else
			//add new item to the list of occurrences
			seen.push_back(v[i]);
	}
}

int main() {

	vector<string> input;
	string temp;

	//Input - thanks to Rui for the algorithm, in the one I used I had to delete the last duplicated item, which made for some good spaghetti
	cout << "Insert the desired strings (ctrl+z to end)" << endl;
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

	cout << "\n\n\n";

	//Eliminating duplicates
	removeDuplicates(input);

	cout << "Without duplicates:\n";
	//Display
	for (int i = 0; i < input.size(); i++) {
		cout << input[i] << endl;
	}

	return 0;
}