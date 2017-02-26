#include <iostream>
using namespace std;

int gcd(int m, int n) {

	//to make sure gcd(a,b) = gcd(b,a)
	if (n > m)
		swap(m, n);

	if (m % n == 0) // if n is a divisor of m, return n
		return n;
	else
		return gcd(m, m % n); // if 
}

int main() {

	int a, b;

	cout << "a ? ";
	cin >> a;
	cout << "b ? ";
	cin >> b;

	cout << "gcd(a,b) = " << gcd(a, b) << endl;

	return 0;
}