#define LABA2TECHNOLOGYOFPROGRAMMING_SIGN_H
#pragma once

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class SIGN {
private:
	string lastName;
	string firstName;
	string zodiacSign;
	int birthday[3];
public:
	SIGN(string last, string first, string sign, int day, int month, int year);
	SIGN(const SIGN &other);
	~SIGN();
	string getLastName() { return lastName; }
	string getFirstName() { return firstName; }
	string getZodiacSign() { return zodiacSign; }
	int* getBirthday() { return birthday; }
	friend ostream& operator<<(ostream& os, const SIGN& obj);

};

