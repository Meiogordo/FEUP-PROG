
#include <iomanip>
#include <iostream>
using namespace std;

int main() {

	cout.precision(3);

	int a, b, c;
	float media;

	cout << "A ? ";
	cin >> a;

	cout << "B ? ";
	cin >> b;

	cout << "C ? ";
	cin >> c;

	media = (float) (a + b + c) / 3;

	cout << "media = " << fixed << media << endl;
	cout << "A-media = " << (a - media) << endl;
	cout << "B-media = " << defaultfloat <<(b - media) << endl;
	cout << "C-media = " << (c - media) << endl;

	//basta usar um modificador e altera todos os outros couts



	return 0;
}