#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//Reads a file from a path and returns a vector of strings with the contents, one string per line
vector<string> ReadFile(string path) {

	vector<string> inputstuff;

	//infile is path

	ifstream myfile;
	string line;

	myfile.open(path);

	while (getline(myfile, line)) {
		inputstuff.push_back(line);
	}

	myfile.close();

	return inputstuff;
}

//Writes to a file
//Note: Will overwrite contents and also create a file if the specified file path does not exist
void OverWriteFile(string path, string towrite) {

	ofstream myfile(path);

	myfile << towrite;

	myfile.close();
}

//Appends text to a file. Puts a line break before the text to append so it is appended in a different line
void AppendToFile(string path, string towrite) {

	ofstream myfile;

	myfile.open(path, ios::app);

	myfile << "\n" << towrite;
}

//Sorts a vector of strings in ascending order
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

//returns %path%_sorted.txt from a %path%.txt string
string getNewFilePath(string oldpath) {
	string output = oldpath.substr(0, oldpath.find_first_of('.'));
	output.append("_sorted.txt");
	return output;
}

int main() {

	string path;

	cout << "What is the path to the file to be sorted? (Example: \"Names.txt\")" << endl;
	cin >> path;

	vector <string> names = ReadFile(path);
	bubblesort(names);

	string newpath = getNewFilePath(path);

	//To create file if non-existant and not append to an empty line, resulting in an empty line in the beggining of the text file
	OverWriteFile(newpath, names[0]);
	//Append the remaining text
	for (int i = 1; i < names.size(); i++) {
		//A new line is appended in the function so there is no need to append it in the function call
		AppendToFile(newpath, names[i]);
	}

	return 0;
}