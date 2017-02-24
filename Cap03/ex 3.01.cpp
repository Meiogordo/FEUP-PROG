#include <iostream>
using namespace std;

double distance(double xa, double ya, double xb, double yb) {
	return sqrt((xb - xa)*(xb - xa) + (yb - ya) * (yb - ya));
}

double area(double xa, double ya, double xb, double yb, double xc, double yc) {


	double a, b, c, sp;

	a = distance(xa, ya, xb, yb); // 1->2
	b = distance(xb, yb, xc, yc); // 2->3
	c = distance(xc, yc, xa, ya); // 3->1

	cout << "Lado a: " << a << "\nLado b: " << b << "\nLado c: " << c;

	sp = (a + b + c) / 2.0; // 2.0 to force float/double

	cout << "\nSemiperimetro: " << sp << endl;

	return sqrt(sp*(sp - a)*(sp - b)*(sp - c));
}

int main() {

	double x1, x2, x3, y1, y2, y3;
	double areafinal;

	cout << "Coordenadas do vertice 1:" << endl;
	cout << "x: ";
	cin >> x1;
	cout << "y: ";
	cin >> y1;
	cout << endl;

	cout << "Coordenadas do vertice 2:" << endl;
	cout << "x: ";
	cin >> x2;
	cout << "y: ";
	cin >> y2;
	cout << endl;

	cout << "Coordenadas do vertice 3:" << endl;
	cout << "x: ";
	cin >> x3;
	cout << "y: ";
	cin >> y3;
	cout << endl;

	areafinal = area(x1, y1, x2, y2, x3, y3);

	cout << "A area do triangulo formado por estes 3 pontos e: " << areafinal << endl;


	return 0;
}