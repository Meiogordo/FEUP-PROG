#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {

	srand(time(NULL));
	int answer;
	int rand1 = rand() % 8 + 2, rand2 = rand() % 8 + 2;

	cout << "Quanto e " << rand1 << " vezes " << rand2 << "?" << endl;

	int result = rand1 * rand2;
	//result = 1; //hardcoded debug

	time_t startTime = time(NULL); //Obtem tempo atual - inicio
	cin >> answer;
	time_t endTime = time(NULL); //Obtem tempo atual -fim

	int timeElapsed = endTime - startTime;

	if (answer != result)
		cout << "Muito Mau, seu noob na multiplicacao!" << endl;
	else if (timeElapsed < 5)
		cout << "Bom" << endl;
	else if (timeElapsed <= 10)
		cout << "Satisfaz, mas podia ser melhor, ja tende para o noob" << endl;
	else
		cout << "Insuficiente, estudar e a melhor opcao" << endl;

	return 0;
}