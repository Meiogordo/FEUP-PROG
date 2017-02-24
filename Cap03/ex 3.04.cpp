#include <iostream>
using namespace std;

double round(double x, unsigned n) {
	return floor(x * pow(10,n) + 0.5) / pow(10,n);
}

int main() {

	double x;
	unsigned n;

	cout << "x ? ";
	cin >> x;
	cout << "n ? ";
	cin >> n;

	cout << round(x, n) << endl;

	return 0;
}