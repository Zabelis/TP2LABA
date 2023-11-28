#define LABA2TECHNOLOGYOFPROGRAMMING_CAR_H
#pragma once

#include "sign.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


SIGN::SIGN(string last, string first, string sign, int day, int month, int year) {
        lastName = last;
        firstName = first;
        zodiacSign = sign;
        birthday[0] = day;
        birthday[1] = month;
        birthday[2] = year;
    }


ostream& operator<<(ostream& os, const SIGN& obj) {
    os << "Last name: " << obj.lastName << endl;
    os << "First name: " << obj.firstName << endl;
    os << "Zodiac sign: " << obj.zodiacSign << endl;
    os << "Birthday: " << obj.birthday[0] << "/" << obj.birthday[1] << "/" << obj.birthday[2] << endl;
    return os;
}

SIGN::SIGN(const SIGN& other) {
    this->firstName = other.firstName;
    this->lastName = other.lastName;
    this->birthday[0] = other.birthday[0];
    this->birthday[1] = other.birthday[1];
    this->birthday[2] = other.birthday[2];
    this->zodiacSign = other.zodiacSign;
    cout << "Sign copy constructor called" << endl;
}

void SIGN::setFirstName(string name) {
    this->firstName = name;
}

void SIGN::setLastName(string name) {
    this->lastName = name;
}

void SIGN::setBirthday(int day, int month, int year) {
    this->birthday[0] = day;
    this->birthday[1] = month;
    this->birthday[2] = year;

}

void SIGN::setZodiacSign(string sign) {
    this->zodiacSign = sign;
}