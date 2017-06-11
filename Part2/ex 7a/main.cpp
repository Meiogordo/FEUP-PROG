#include <iostream>
#include "Vector.h"

template<class T> class Vector;

using namespace std;

//Template function for printing Vectors - useful for testing
template<typename T>
void printVec(const Vector<T> &v){
	for(unsigned int i = 0; i < v.size(); ++i){
		cout << i << ": " << v[i] << endl;
	}
}


int main(){
	Vector<int> v1(5,2);
	printVec(v1);
	cout << "size: " << v1.size() << " pushb" << endl;
	v1.push_back(5);
	v1.push_back(69);
	printVec(v1);
	cout << "size: " << v1.size() << " popback" << endl;
	v1.pop_back();
	v1.pop_back();
	printVec(v1);
	cout << "size: " << v1.size() << endl;
}
