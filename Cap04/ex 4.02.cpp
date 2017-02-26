#include <iostream>
#include <string>
using namespace std;

bool sequenceSearch(string s, int nc, char c) {

	//creating search string
	string findme;
	for (int i = 0; i < nc; i++) {
		findme.push_back(c);
	}

	if (s.find(findme) != -1)
		return true;
	else
		return false;
}

int main() {

	cout << sequenceSearch("123122111000", 3, '1') << endl;

	return 0;
}