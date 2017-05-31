/*
 * Person.h
 *
 *  Created on: 30/05/2017
 *      Author: miguel
 */

#pragma once

#include <string>
#include "Date.h"

using namespace std;

class Person {
public:
	Person(string name, char gender, Date birthdate);
	~Person();

	const Date& getBirthdate() const;
	char getGender() const;
	void setGender(char gender);
	const string& getName() const;
	void setName(const string& name);

private:
	string name;
	char gender; //'M' for Male and 'F' for Female
	Date birthdate;
};
