#ifndef TP_1LABA_EXCEPTION_H
#define TP_1LABA_EXCEPTION_H
#pragma once

#include <iostream>

using std::ostream;

class Exception {
private:
    const char* textEx;
public:
    Exception(const char* a) : textEx(a) {};

    friend ostream& operator<<(ostream& stream, const Exception& a) {
        stream << "Error!\n" << a.textEx;
        return stream;
    }
};

#endif