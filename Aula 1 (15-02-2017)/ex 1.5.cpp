
#include <iostream>
using namespace std;

int main() {

	int h1, m1, s1, h2, m2, s2, dsum = 0, hsum = 0, msum = 0, ssum = 0;

	cout << "Tempo 1 (horas minutos segundos) ? ";
	cin >> h1 >> m1 >> s1;

	cout << "Tempo 2 (horas minutos segundos) ? ";
	cin >> h2 >> m2 >> s2;

	for (ssum = s1 + s2; ssum > 60; ssum -= 60, msum++) {}
	for (msum = m1 + m2 + msum; msum > 60; msum -= 60, hsum++) {}
	for (hsum = hsum + h1 + h2; hsum > 24; hsum -= 24, dsum++) {}
	

	cout << "Soma dos tempos: " << dsum << ((dsum > 1 || dsum == 0) ? " dias" : " dia")
		<< ", " << hsum << ((hsum > 1 || hsum == 0) ? " horas" : " hora")
		<< ", " << msum << ((msum > 1 || msum == 0) ? " minutos" : " minuto")
		<< " e " << ssum << ((ssum > 1 || ssum == 0) ? " segundos" : " segundo") << endl;


	return 0;
}