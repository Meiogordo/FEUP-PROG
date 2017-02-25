#include <iostream>
#include <climits>
using namespace std;

long int factorial_ite(int in) {
	long int out = 1;
	while (in > 1) {
		out *= in;
		in--;
	}
	return out;
}

long int factorial_rec(int in) {
	if (in <= 1)
		return 1;
	else
		return in*factorial_rec(in - 1);
}

int main() {

	//Tests for maxsize. 20 as input results in overflow, so the max input with long int is 19.
	/*cout << LONG_MAX << endl;
	cout << factorial_ite(19) << endl;*/

	cout << factorial_ite(12) << endl;
	cout << factorial_rec(12) << endl;

	return 0;
}