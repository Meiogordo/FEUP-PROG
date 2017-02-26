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

int binarySearch(const vector<string> &v, string value) {
	int bottom = 0;
	int top = v.size() - 1;
	int middle;
	bool found = false; //not entirely necessary, could just return the index when found 
	//and the loop would exit itself when not found with the other condition so we only needed to return -1 after the loop.
	//Still, I am using it to stick with the requested structure. Feel free to make yours without this var

	while (bottom <= top && !found) {
		middle = (top + bottom) / 2;

		if (v[middle] == value)
			found = true;
		else
			if (v[middle].compare(value) < 0)
				bottom = middle + 1;
			else
				top = middle - 1;
	}

	if (found)
		return middle;
	else
		return -1;
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

	//Searching for a string
	string search;
	cout << "Insert the string to search for: ";
	cin >> search;
	int searchresult = binarySearch(input, search);
	if (searchresult != -1)
		cout << "String found at index " << searchresult << endl;
	else
		cout << "String not found..." << endl;

	return 0;
}