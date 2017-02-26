#include <iostream>
using namespace std;

struct Fraction {
	int numerator;
	int denominator;
};

void writeFracc(int numerator, int denominator);
bool readFracc(int &numerator, int &denominator);
void reduceFracc(int &numerator, int &denominator);
int gcd(int n1, int n2);
void addFracs(int num1, int denom1, int num2, int denom2);
void subtractFracs(int num1, int denom1, int num2, int denom2);
void multiplyFracs(int num1, int denom1, int num2, int denom2);
void divideFracs(int num1, int denom1, int num2, int denom2);

Fraction reduceFracc(Fraction f) {
	Fraction out;
	int divisor = gcd(f.numerator, f.denominator);
	out.numerator = f.numerator / divisor;
	out.denominator = f.denominator / divisor;

	return out;
}

void writeFracc(Fraction f) {
	cout << f.numerator << "/" << f.denominator << endl;
}

Fraction readFracc() {

	Fraction output;

	char separatorchar;
	cin >> output.numerator >> separatorchar >> output.denominator;
	if (cin.fail() || separatorchar != '/' || output.denominator == 0) {
		cin.clear();
		output.numerator = 0;
		output.denominator = 0;
	}

	return output;
}

Fraction addFracs(Fraction f1, Fraction f2)
{
	Fraction output;

	//equal denominators
	if (f1.denominator == f2.denominator) {
		output.numerator = f1.numerator + f2.numerator;
		output.denominator = f1.denominator;
	}
	//different denominators
	//should get lcm of denominators and multiply each side by the lcm divided by the respective denominator
	//however, it's easier to multiply one by the other and let reduceFracc do the reducing part
	else {
		output.numerator = (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator);
		output.denominator = f1.denominator * f2.denominator;
	}

	output = reduceFracc(output);
	return output;
}

Fraction subtractFracs(Fraction f1, Fraction f2)
{
	Fraction output;

	//equal denominators
	if (f1.denominator == f2.denominator) {
		output.numerator = f1.numerator - f2.numerator;
		output.denominator = f1.denominator;
	}
	//different denominators
	//same as in addFracs (see that function for details on this)
	else {
		output.numerator = (f1.numerator * f2.denominator) - (f2.numerator * f1.denominator);
		output.denominator = f1.denominator * f2.denominator;
	}

	output = reduceFracc(output);
	return output;
}

Fraction multiplyFracs(Fraction f1, Fraction f2)
{
	// a/b * c/d = a*c/b*d
	Fraction output;
	output.numerator = f1.numerator * f2.numerator;
	output.denominator = f1.denominator * f2.denominator;

	output = reduceFracc(output);
	return output;
}

Fraction divideFracs(Fraction f1, Fraction f2)
{
	// a/b / c/d = a/b * c/d = a*c/b*d
	Fraction output;
	output.numerator = f1.numerator * f2.denominator;
	output.denominator = f1.denominator * f2.numerator;

	output = reduceFracc(output);
	return output;
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

	Fraction f1;

	cout << "Insert fraction in N/D format, where N is the numerator and D is the denominator\nFraction: ";
	f1 = readFracc();

	cout << endl;
	writeFracc(f1);

	cout << "The reduced fraction is: ";
	f1 = reduceFracc(f1);
	writeFracc(f1);

	Fraction f2;

	cout << endl;
	cout << "Insert second fraction in N/D format, where N is the numerator and D is the denominator\nFraction: ";
	f2 = readFracc();

	cout << endl;
	writeFracc(f2);

	cout << "The reduced second fraction is: ";
	f2 = reduceFracc(f2);
	writeFracc(f2);

	cout << endl;

	cout << "Operations:" << endl;

	cout << "The sum is: ";
	writeFracc(addFracs(f1, f2));


	cout << "The difference is: ";
	writeFracc(subtractFracs(f1, f2));


	cout << "The product is: ";
	writeFracc(multiplyFracs(f1, f2));


	cout << "The quotient is: ";
	writeFracc(divideFracs(f1, f2));

	return 0;
}