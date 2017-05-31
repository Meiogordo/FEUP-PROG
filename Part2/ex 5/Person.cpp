/*
 * Person.cpp
 *
 *  Created on: 30/05/2017
 *      Author: miguel
 */

#include "Person.h"

Person::Person(string name, char gender, Date birthdate)
: name(name), gender(gender), birthdate(birthdate)
{};

Person::~Person() {
	// TODO Auto-generated destructor stub
}

const Date& Person::getBirthdate() const {
	return birthdate;
}

char Person::getGender() const {
	return gender;
}

void Person::setGender(char gender) {
	this->gender = gender;
}

const string& Person::getName() const {
	return name;
}

void Person::setName(const string& name) {
	this->name = name;
}
