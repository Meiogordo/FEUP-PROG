/*
 * Date.cpp
 *
 *  Created on: 30/05/2017
 *      Author: miguel
 */

#include "Date.h"

Date::Date() {

	//This is probably magic so do not touch
	time_t t = time(0);   // gets current time

	// big voodoo black magic (in truth C time libraries with possibly some c++ tweaks if I'm not mistaken)
	tm* now = localtime(&t);

	this->year = now->tm_year + 1900; //gets years since 1900 so we add 1900
	this->month = now->tm_mon + 1; //gets months since january (where month is [0,11] so we add 1)
	this->day = now->tm_mday; //gets day of the month [1,31] -> no aditional math required

}

Date::Date(unsigned int year, unsigned int month, unsigned int day) :
		year(year), month(month), day(day) {
	//Possible solution but it is generally better to use a member initialization list like done above
	/*
	 (*this).year = year;
	 (*this).month = month;
	 (*this).day = day;
	 */
}

Date::Date(string yearMonthDay) {
	//Could be done with hardcoded positions - for example substr(0,4) is year, etc
	(*this).year = stoi(yearMonthDay.substr(0, yearMonthDay.find('/'))); //gets yyyy
	yearMonthDay = yearMonthDay.substr(yearMonthDay.find('/') + 1); //changed into mm/dd
	(*this).month = stoi(yearMonthDay.substr(0, yearMonthDay.find('/'))); //gets mm
	yearMonthDay = yearMonthDay.substr(yearMonthDay.find('/') + 1); //changed into dd
	(*this).day = stoi(yearMonthDay);
}

void Date::setYear(unsigned int year) {
	this->year = year;
}

void Date::setMonth(unsigned int month) {
	this->month = month;
}

void Date::setDay(unsigned int day) {
	this->day = day;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}

unsigned int Date::getYear() {
	return year;
}

unsigned int Date::getMonth() {
	return month;
}

unsigned int Date::getDay() {
	return day;
}

string Date::getDate() {
	return to_string(year) + "/" + to_string(month) + "/" + to_string(day);
}

void Date::show() {
	cout << year << "/" << month << "/" << day << endl;
}

bool Date::isValid() {
	return (day <= daysInMonth(month, year)) && (month >= 1 && month <= 12);
}

bool Date::isEqualTo(const Date &d) {
	return (d.year == year && d.month == month && d.day == day);
}

bool Date::isNotEqualTo(const Date &d) {
	return !isEqualTo(d);
}

bool Date::isAfter(const Date &d) {
	if (d.year > year)
		return false;
	else if (d.year == year && d.month > month)
		return false;
	else if (d.year == year && d.month == month && d.day > day)
		return false;
	else
		return true;
}

bool Date::isBefore(const Date &d) {
	return !isAfter(d);
}

bool Date::isBissexto(int year) {
	// Divisible by 4 but not by 100, or divisible by 400
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	else
		return false;
}

int Date::daysInMonth(int month, int year) {
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		if (isBissexto(year))
			return 29;
		else
			return 28;
	default:
		return -1;
	}
}
