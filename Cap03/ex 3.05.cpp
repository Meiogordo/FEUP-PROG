#include <iostream>
using namespace std;

void writeFracc(int numerator, int denominator);
bool readFracc(int &numerator, int &denominator);
void reduceFracc(int &numerator, int &denominator);
int gcd(int n1, int n2);
void addFracs(int num1, int denom1, int num2, int denom2);
void subtractFracs(int num1, int denom1, int num2, int denom2);
void multiplyFracs(int num1, int denom1, int num2, int denom2);
void divideFracs(int num1, int denom1, int num2, int denom2);

void reduceFracc(int &numerator, int &denominator) {
	int divisor = gcd(numerator, denominator);
	numerator /= divisor;
	denominator /= divisor;
}

void writeFracc(int numerator, int denominator) {
	cout << numerator << "/" << denominator << endl;
}

bool readFracc(int &numerator, int &denominator) {

	char separatorchar;
	cin >> numerator >> separatorchar >> denominator;
	if (cin.fail() || separatorchar != '/' || denominator == 0) {
		cin.clear();
		numerator = 0;
		denominator = 0;
		return false;
	}
	else
		return true;

}



void addFracs(int num1, int denom1, int num2, int denom2)
{
	int resnum, resdenom;

	//equal denominators
	if (denom1 == denom2) {
		resnum = num1 + num2;
		resdenom = denom1;
	}
	//different denominators
	//should get lcm of denominators and multiply each side by the lcm divided by the respective denominator
	//however, it's easier to multiply one by the other and let reduceFracc do the reducing part
	else {
		resnum = (num1 * denom2) + (num2 * denom1);
		resdenom = denom1 * denom2;
	}

	reduceFracc(resnum, resdenom);

	cout << "The sum is: ";
	writeFracc(resnum, resdenom);

}

void subtractFracs(int num1, int denom1, int num2, int denom2)
{
	int resnum, resdenom;

	//equal denominators
	if (denom1 == denom2) {
		resnum = num1 - num2;
		resdenom = denom1;
	}
	//different denominators
	//same as in addFracs (see that function for details on this)
	else {
		resnum = (num1 * denom2) - (num2 * denom1);
		resdenom = denom1 * denom2;
	}

	reduceFracc(resnum, resdenom);

	cout << "The difference is: ";
	writeFracc(resnum, resdenom);
}

void multiplyFracs(int num1, int denom1, int num2, int denom2)
{
	// a/b * c/d = a*c/b*d
	int resnum = num1 * num2, resdenom = denom1 * denom2;

	reduceFracc(resnum, resdenom);

	cout << "The product is: ";
	writeFracc(resnum, resdenom);
}

void divideFracs(int num1, int denom1, int num2, int denom2)
{
	// a/b / c/d = a/b * c/d = a*c/b*d
	int resnum = num1 * denom2, resdenom = denom1 * num2;

	reduceFracc(resnum, resdenom);

	cout << "The quotient is: ";
	writeFracc(resnum, resdenom);
}

int gcd(int n1, int n2) {
	int divisor = 1;
	int imax = n1 > n2 ? n2 : n1; // limit for loop will be the smallest of the two
	// at most the gcd of n1 and n2 will be the smallest of the two

	for (int i = 1; i <= imax; i++) {
		if (n1 % i == 0 && n2 % i == 0)
			divisor = i;
	}

	return divisor;
}

int main() {

	int numerator;
	int denominator;

	cout << "Insert fraction in N/D format, where N is the numerator and D is the denominator\nFraction: ";
	readFracc(numerator, denominator);

	cout << endl;
	writeFracc(numerator, denominator);

	cout << "The reduced fraction is: ";
	reduceFracc(numerator, denominator);
	writeFracc(numerator, denominator);

	int numerator2;
	int denominator2;

	cout << endl;
	cout << "Insert second fraction in N/D format, where N is the numerator and D is the denominator\nFraction: ";
	readFracc(numerator2, denominator2);

	cout << endl;
	writeFracc(numerator2, denominator2);

	cout << "The reduced second fraction is: ";
	reduceFracc(numerator2, denominator2);
	writeFracc(numerator2, denominator2);

	cout << endl;

	cout << "Operations:" << endl;

	addFracs(numerator, denominator, numerator2, denominator2);
	subtractFracs(numerator, denominator, numerator2, denominator2);
	multiplyFracs(numerator, denominator, numerator2, denominator2);
	divideFracs(numerator, denominator, numerator2, denominator2);

	return 0;
}