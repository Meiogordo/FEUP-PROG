#include <iostream>
using namespace std;

double distanceinplane(double xa, double ya, double xb, double yb) {
	return sqrt((xb - xa)*(xb - xa) + (yb - ya) * (yb - ya));
}

int main() {

	double x1, x2, x3, y1, y2, y3;
	double a, b, c, sp;
	double area;

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

	a = distanceinplane(x1, y1, x2, y2); // 1->2
	b = distanceinplane(x2, y2, x3, y3); // 2->3
	c = distanceinplane(x3, y3, x1, y1); // 3->1

	cout << "Lado a: " << a << "\nLado b: " << b << "\nLado c: " << c;

	sp = (a + b + c) / 2.0; // 2.0 to force float/double

	cout << "\nSemiperimetro: " << sp << endl;

	area = sqrt(sp*(sp-a)*(sp-b)*(sp-c));

	cout << "A area do triangulo formado por estes 3 pontos e: " << area << endl;


	return 0;
}