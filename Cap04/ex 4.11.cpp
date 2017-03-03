#include <iostream>
#include <vector>
using namespace std;

void removeDuplicates(vector<int> &v) {
	//removes duplicates from a vector.
	//The resizing part is much much easier using vector.erase but I wanted to try to use .resize like the exercise said.
	vector <int> seen;
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

void bubblesort(vector<int> &v) {

	bool flag = true;
	int lengthofarr = v.size();
	int comparison;

	while (flag && lengthofarr > 0) {

		lengthofarr--; // because the last element is already sorted
		flag = false;

		for (int i = 0; i < lengthofarr; i++) {
			if (v[i + 1] < v[i]) { // switch if bigger
				swap(v[i], v[i + 1]);
				flag = true;
			}
		}
	}

}

vector<int> unionfunc(const vector<int> &v1, const vector<int> &v2) {

	vector<int> output;

	for (int i = 0; i < v1.size(); i++)
		output.push_back(v1[i]);

	for (int i = 0; i < v2.size(); i++)
		output.push_back(v2[i]);

	removeDuplicates(output);
	bubblesort(output);

	return output;
}

vector<int> intersection(const vector<int> &v1, const vector<int> &v2) {
	vector <int> output;

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v2.size(); j++) {
			if (v2[j] == v1[i]) {
				output.push_back(v1[i]);
				break;
			}
		}
	}

	removeDuplicates(output);
	bubblesort(output);

	return output;
}

int main() {

	vector <int> vec1, vec2;

	vec1 = { 1,2,2,2,2,2,2,2,3,3,3,5,5,7,9,9 };
	vec2 = { 2,7,4 };

	cout << "vec1:\n";
	for (int i = 0; i < vec1.size(); i++)
		cout << i << ": " << vec1[i] << endl;

	cout << "\n\nvec2:\n";
	for (int i = 0; i < vec2.size(); i++)
		cout << i << ": " << vec2[i] << endl;

	vector <int> intersect = intersection(vec1, vec2);
	vector <int> united = unionfunc(vec1, vec2);

	cout << "\n\nintersection:\n";
	for (int i = 0; i < intersect.size(); i++)
		cout << i << ": " << intersect[i] << endl;

	cout << "\n\nunion:\n";
	for (int i = 0; i < united.size(); i++)
		cout << i << ": " << united[i] << endl;

	return 0;
}