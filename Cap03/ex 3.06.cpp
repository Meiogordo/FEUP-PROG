#include <iostream>
#include <string>
using namespace std;

bool isBissexto(int year) {
	//Divisible by 4 but not by 100, or divisible by 400
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	}
	else
		return false;
}

int getMonthCode(int month, int year) {
	if (isBissexto(year))
		switch (month) {
		case 1:
			return 6;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		case 4:
			return 6;
			break;
		case 5:
			return 1;
			break;
		case 6:
			return 4;
			break;
		case 7:
			return 6;
			break;
		case 8:
			return 2;
			break;
		case 9:
			return 5;
			break;
		case 10:
			return 0;
			break;
		case 11:
			return 3;
			break;
		case 12:
			return 5;
			break;
		default:
			return -1;
		}
	else
		switch (month) {
		case 1:
			return 0;
			break;
		case 2:
			return 3;
			break;
		case 3:
			return 3;
			break;
		case 4:
			return 6;
			break;
		case 5:
			return 1;
			break;
		case 6:
			return 4;
			break;
		case 7:
			return 6;
			break;
		case 8:
			return 2;
			break;
		case 9:
			return 5;
			break;
		case 10:
			return 0;
			break;
		case 11:
			return 3;
			break;
		case 12:
			return 5;
			break;
		default:
			return -1;
		}
}

string monthNumberToName(int month) {
	switch (month)
	{
	case 1:
		return "Janeiro";
		break;
	case 2:
		return "Fevereiro";
		break;
	case 3:
		return "Marco";
		break;
	case 4:
		return "Abril";
		break;
	case 5:
		return "Maio";
		break;
	case 6:
		return "Junho";
		break;
	case 7:
		return "Julho";
		break;
	case 8:
		return "Agosto";
		break;
	case 9:
		return "Setembro";
		break;
	case 10:
		return "Outubro";
		break;
	case 11:
		return "Novembro";
		break;
	case 12:
		return "Dezembro";
		break;
	default:
		return "Mes invalido";
		break;
	}
}

int dayOfWeek(int day, int month, int year) {
	int monthCode = getMonthCode(month, year);
	int firstTwoOfYear = year / 100;
	int lastTwoOfYear = year % 100;

	return ((int)(floor((5 * lastTwoOfYear) / 4) + monthCode + day - 2 * (firstTwoOfYear % 4) + 7) % 7);
}

string interpretDayOfWeek(int input) {
	switch (input) {
	case 0:
		return "Sabado";
		break;
	case 1:
		return "Domingo";
		break;
	case 2:
		return "Segunda-feira";
		break;
	case 3:
		return "Terca-feira";
		break;
	case 4:
		return "Quarta-feira";
		break;
	case 5:
		return "Quinta-feira";
		break;
	case 6:
		return "Sexta-feira";
		break;
	default:
		return "erro";
	}
}

string getDayOfWeekTextFromDate(int day, int month, int year) {
	return interpretDayOfWeek(dayOfWeek(day, month, year));
}

int nrOfDaysInMonth(int month, int year) {
	switch (month) {
	case 1:
		return 31;
		break;
	case 2:
		if (isBissexto(year))
			return 29;
		else
			return 28;
		break;
	case 3:
		return 31;
		break;
	case 4:
		return 30;
		break;
	case 5:
		return 31;
		break;
	case 6:
		return 30;
		break;
	case 7:
		return 31;
		break;
	case 8:
		return 31;
		break;
	case 9:
		return 30;
		break;
	case 10:
		return 31;
		break;
	case 11:
		return 30;
		break;
	case 12:
		return 31;
		break;
	default:
		return 0;
	}
}

void printMonthCalendar(int month, int year) {
	int maxDays = nrOfDaysInMonth(month, year);
	cout << monthNumberToName(month) << "/" << year << endl;
	cout << "Dom\tSeg\tTer\tQua\tQui\tSex\tSab" << endl;
	int firstWeekDay = dayOfWeek(1, month, year);
	int nDaysFirstWeek = 8 - firstWeekDay == 8 ? 1 : 8 - firstWeekDay;

	//fixing formatting zzz
	cout << "";

	for (int i = 1; i <= 7 - nDaysFirstWeek; i++)
		cout << "\t"; // Add tab before

	for (int d = 1; d <= nDaysFirstWeek; d++)
		cout << d << "\t";

	cout << endl;
	int dayofweekat = 0;
	for (int d = nDaysFirstWeek + 1; d <= maxDays; d++) {
		cout << d << "\t";
		dayofweekat++;
		if (dayofweekat % 7 == 0) {
			cout << endl;
		}
	}

	cout << endl;
}

int main() {

	int ano, mes, dia;

	//Testing printing yearly calendar
	cout << "Insira o ano desejado: ";
	cin >> ano;

	for (int m = 1; m <= 12; m++)
	{
		printMonthCalendar(m, ano);
		cout << endl;
	}


	//Testing printing monthly calendar
	/*cout << "Insira o ano desejado: ";
	cin >> ano;
	cout << "Insira o mes desejado (numero de 1 a 12): ";
	cin >> mes;

	printMonthCalendar(mes, ano);*/


	//Testing dayOfWeek
	/*cout << "Insira o dia a testar: ";
	cin >> dia;
	cout << "Insira o mes a testar (numero de 1 a 12): ";
	cin >> mes;
	cout << "Insira o ano a testar: ";
	cin >> ano;

	//cout << "O dia da semana e " << interpretDayOfWeek(dayOfWeek(dia, mes, ano)) << endl;
	cout << "O dia da semana e " << getDayOfWeekTextFromDate(dia, mes, ano) << endl;*/

	//Testing nrOfDaysInMonth
	/*cout << "Insira o mes a testar (numero de 1 a 12): ";
	cin >> mes;
	cout << "Insira o ano a testar: ";
	cin >> ano;

	cout << "Em " << ano << " o mes " << mes << " tem " << nrOfDaysInMonth(mes, ano) << " dias." << endl;*/

	//Testing ano bissexto
	/*cout << "Insira o ano a testar: ";
	cin >> ano;

	cout << ano << (isBissexto(ano) ? " e bissexto." : " nao e bissexto.") << endl;*/

	return 0;
}