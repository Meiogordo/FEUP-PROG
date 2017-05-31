/*
 * Date.h
 *
 *  Created on: 30/05/2017
 *      Author: miguel
 */

#pragma once

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Date
{
public:
	//default constructor - uses current date
	Date();
	Date(unsigned int year, unsigned int month, unsigned int day);
	// yearMonthDay must be in format "yyyy/mm/dd"
	Date(string yearMonthDay);
	void setYear(unsigned int year);
	void setMonth(unsigned int month);
	void setDay(unsigned int day);
	void setDate(unsigned int year, unsigned int month, unsigned int day);
	unsigned int getYear();
	unsigned int getMonth();
	unsigned int getDay();
	// returns the date in format "yyyy/mm/dd"
	string getDate();
	// shows the date on the screen in format "yyyy/mm/dd"
	void show();
	// true if the date is valid - day is at most the number of days in the month and month is between 1 and 12
	bool isValid();
	// checking if two date objects hold the same data
	bool isEqualTo(const Date &d);
	//isNotEqualTo is isEqualTo negated
	bool isNotEqualTo(const Date &d);
	//check if the internal date is after a given date object
	bool isAfter(const Date &d);
	//once again lazy implementation -> don't do this at home kids
	bool isBefore(const Date &d);
private:
	unsigned int year;
	unsigned int month;
	unsigned int day;
	//true if the year is a leap year (ano bissexto), false if not
	bool isBissexto(int year);
	//returns the number of days in a certain month
	int daysInMonth(int month, int year);
};
