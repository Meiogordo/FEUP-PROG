#include <iostream>
#include "Vector.h"
#include <vector>

using namespace std;

//Template function for printing Vectors - useful for testing
template<typename T>
void printVec(const Vector<T> &v) {
	for (unsigned int i = 0; i < v.size(); ++i) {
		cout << i << ": " << v[i] << endl;
	}
}

int main() {
	/*
	 //Concluding how STL Vectors allocate memory
	 //Every time that the memory reaches its limit, double the memory is allocated
	 vector<int> vec1;
	 cout << "capacity: " << vec1.capacity() << "\t size: " << vec1.size() << endl;

	 for (unsigned int i = 0;  i < 100; ++i) {
	 vec1.push_back(1);
	 cout << "capacity: " << vec1.capacity() << "\t size: " << vec1.size() << endl;
	 }
	 */

	//If given size at vector creation, .size and .capacity are the same
	/*
	 vector<int> vec2(69);
	 cout << "capacity: " << vec2.capacity() << "\t size: " << vec2.size() << endl;
	 */

	//Now testing with Vector stuff
	Vector<int> vec1;
	cout << "capacity: " << vec1.capacity() << "\t size: " << vec1.size()
			<< endl;

	for (unsigned int i = 0; i < 100; ++i) {
		vec1.push_back(1);
		cout << "capacity: " << vec1.capacity() << "\t size: " << vec1.size()
				<< endl;
	}
	vec1.push_back(2);
	printVec(vec1);
}
