#include "sign.h"
#include "keeper.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


Keeper::Keeper() {
    signs = new SIGN * [1];
    numSigns = 0;
}

void Keeper::addSign(SIGN* sign) {
        SIGN** temp = new SIGN * [numSigns + 1];
        for (int i = 0; i < numSigns; i++) {
            temp[i] = signs[i];
        }
        temp[numSigns] = sign;
        delete[] signs;
        signs = temp;
        numSigns++;
    }

void Keeper::removeSign(int index) {
        if (index < 0 || index >= numSigns) return;
        SIGN** temp = new SIGN * [numSigns - 1];
        for (int i = 0; i < index; i++) {
            temp[i] = signs[i];
        }
        for (int i = index + 1; i < numSigns; i++) {
            temp[i - 1] = signs[i];
        }
        delete[] signs;
        signs = temp;
        numSigns--;
    }

    void Keeper::printSigns() {
        for (int i = 0; i < numSigns; i++) {
            cout << *signs[i] << endl;
        }
    }

    int Keeper::getnumSigns() {
        return this->numSigns;
    }

    SIGN* Keeper::getSign(int i) {
        return this->signs[i];
    }

    void Keeper::sortByBirthDate() {
        sort(signs, signs + numSigns, [](SIGN* a, SIGN* b) {
            return compareSignDates(a, b);
            });
    }

    bool Keeper::compareSignDates(SIGN* a, SIGN* b) {
        if (a->getBirthday()[2] != b->getBirthday()[2]) {
            return a->getBirthday()[2] < b->getBirthday()[2];
        }
        else if (a->getBirthday()[1] != b->getBirthday()[1]) {
            return a->getBirthday()[1] < b->getBirthday()[1];
        }
        else {
            return a->getBirthday()[0] < b->getBirthday()[0];
        }
    }

    void Keeper::setSign(SIGN* profile, int index) {
        this->signs[index] = profile;

    }
