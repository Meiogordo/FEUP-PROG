#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

template<class T>
pair<T, T> getMinMax(const vector<T> &v) {
	//Starting the pair with some value to make the comparisons work
	pair<T, T> smallerBigger = { v[0], v[0] }; //First part of pair is the smaller element second part is bigger

	//Using range-based for loops is cool!
	for (const auto &it : v) {
		if (it < smallerBigger.first)
			smallerBigger.first = it;
		if (it > smallerBigger.second)
			smallerBigger.second = it;
	}

	return smallerBigger;
}

int main() {

	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(-5);
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(508);
	vec.push_back(69);
	vec.push_back(-10);

	//Too lazy to type out pair syntax
	auto result = getMinMax(vec);

	cout << "min: " << result.first << " max: " << result.second << endl;

	return 0;
}
