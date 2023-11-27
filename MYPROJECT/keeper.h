#pragma once
#include "sign.h"
using namespace std;



class Keeper {
private:
    SIGN** signs;
    int numSigns;

public:
    Keeper();

    void addSign(SIGN* sign);

    void removeSign(int index);

    void printSigns();

    int getnumSigns();

    SIGN* getSign(int i);

    void sortByBirthDate();

    static bool compareSignDates(SIGN* a, SIGN* b);
};