#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Date
{
public:
	//default constructor - uses current date
	Date() {

		//This is probably magic so do not touch
		time_t t = time(0);   // gets current time

		// big voodoo black magic (in truth C time libraries with possibly some c++ tweaks if I'm not mistaken)
		struct tm now;
		localtime_s(&now, &t);

		(*this).year = now.tm_year + 1900; //gets years since 1900 so we add 1900
		(*this).month = now.tm_mon + 1; //gets months since january (where month is [0,11] so we add 1)
		(*this).day = now.tm_mday; //gets day of the month [1,31] -> no aditional math required

	}
	Date(unsigned int year, unsigned int month, unsigned int day) : year(year), month(month), day(day) {
		//Possible solution but it is generally better to use a member initialization list like done above
		/*
		(*this).year = year;
		(*this).month = month;
		(*this).day = day;
		*/
	}
	// yearMonthDay must be in format "yyyy/mm/dd"
	Date(string yearMonthDay) {
		//Could be done with hardcoded positions - for example substr(0,4) is year, etc
		(*this).year = stoi(yearMonthDay.substr(0, yearMonthDay.find('/'))); //gets yyyy
		yearMonthDay = yearMonthDay.substr(yearMonthDay.find('/') + 1); //changed into mm/dd
		(*this).month = stoi(yearMonthDay.substr(0, yearMonthDay.find('/'))); //gets mm
		yearMonthDay = yearMonthDay.substr(yearMonthDay.find('/') + 1); //changed into dd
		(*this).day = stoi(yearMonthDay);
	}
	void setYear(unsigned int year) { (*this).year = year; }
	void setMonth(unsigned int month) { (*this).month = month; }
	void setDay(unsigned int day) { (*this).day = day; }
	void setDate(unsigned int year, unsigned int month, unsigned int day) {
		(*this).year = year;
		(*this).month = month;
		(*this).day = day;
	}
	unsigned int getYear() { return year; }
	unsigned int getMonth() { return month; }
	unsigned int getDay() { return day; }
	// returns the date in format "yyyy/mm/dd"
	string getDate() {
		return to_string(year) + "/" + to_string(month) + "/" + to_string(day);
	}
	// shows the date on the screen in format "yyyy/mm/dd"
	void show() {
		cout << year << "/" << month << "/" << day << endl;
	}
	// true if the date is valid - day is at most the number of days in the month and month is between 1 and 12
	bool isValid() {
		return (day <= daysInMonth(month, year)) && (month >= 1 && month <= 12);
	}
	// checking if two date objects hold the same data
	bool isEqualTo(const Date &d) {
		return (d.year == year && d.month == month && d.day == day);
	}
	//isNotEqualTo is isEqualTo negated
	bool isNotEqualTo(const Date &d) { return !isEqualTo(d); }
	//check if the internal date is after a given date object
	bool isAfter(const Date &d) {
		if (d.year > year)
			return false;
		else if (d.year == year && d.month > month)
			return false;
		else if (d.year == year && d.month == month && d.day > day)
			return false;
		else
			return true;
	}
	//once again lazy implementation -> don't do this at home kids
	bool isBefore(const Date &d) {
		return !isAfter(d);
	}
private:
	unsigned int year;
	unsigned int month;
	unsigned int day;
	//true if the year is a leap year (ano bissexto), false if not
	bool isBissexto(int year) {
		// Divisible by 4 but not by 100, or divisible by 400
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return true;
		else
			return false;
	}
	//returns the number of days in a certain month
	int daysInMonth(int month, int year) {
		switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			if (isBissexto(year)) return 29;
			else return 28;
		default:
			return -1;
		}
	}
};


int main() {
	//Initialization through unsigned ints directly
	Date d1(1998, 10, 24);
	//Initialization through string
	Date d2("2017/04/06");

	//Printing data
	cout << "d1: ";
	d1.show();
	cout << "d2: ";
	d2.show();

	//Testing setters for d2
	d2.setYear(2016);
	d2.setMonth(10);
	d2.setDay(25);

	//Printing changes to d2
	cout << "d2 after first set: ";
	d2.show();

	//Testing getters in a print
	cout << "The values of d1 are: " << d1.getDay() << " for day, " << d1.getMonth() << " for month, and " << d1.getYear() << " for year." << endl;

	//Getting the string for the date directly
	cout << "The string for date that d1 returns is: " << d1.getDate() << endl;

	//Setter with the 3 variables
	d2.setDate(2023, 5, 57);

	//Printing changes to d2
	cout << "d2 after second set: ";
	d2.show();

	//2nd part
	cout << "\n\n\n";

	//seeing if d2 is valid
	if (d2.isValid())
		cout << "d2 is valid";
	else
		cout << "d2 is invalid";
	cout << endl;

	//seeing if d1 is valid
	if (d1.isValid())
		cout << "d1 is valid";
	else
		cout << "d1 is invalid";
	cout << endl;

	//Testing before/after
	//If not sure what ( ? : ) is search for 'ternary operators'
	cout << (d1.isAfter(d2) ? d1.getDate() + " is after " + d2.getDate() : d1.getDate() + " is not after " + d2.getDate()) << endl;
	cout << (d1.isBefore(d2) ? d1.getDate() + " is before " + d2.getDate() : d1.getDate() + " is not before " + d2.getDate()) << endl;

	//Did not fully understand E, maybe change show() or getDate() to yyyymmdd?
	//If we are to change the constructor then main has to be changed so that can't be it
	//(Also potentially use the internal data as a string but that is too much of a pain to implement without any valid point)

	//F: It is not possible because there is no constructor without arguments

	//Testing G
	Date dtest;
	cout << "Testing current date: ";
	dtest.show();
	return 0;
}