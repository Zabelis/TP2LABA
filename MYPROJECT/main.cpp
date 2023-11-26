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
    SIGN(string last, string first, string sign, int day, int month, int year) {
        lastName = last;
        firstName = first;
        zodiacSign = sign;
        birthday[0] = day;
        birthday[1] = month;
        birthday[2] = year;
    }

    string getLastName() { return lastName; }
    string getFirstName() { return firstName; }
    string getZodiacSign() { return zodiacSign; }
    int* getBirthday() { return birthday; }

    friend ostream& operator<<(ostream& os, const SIGN& obj);
};

ostream& operator<<(ostream& os, const SIGN& obj) {
    os << "Last name: " << obj.lastName << endl;
    os << "First name: " << obj.firstName << endl;
    os << "Zodiac sign: " << obj.zodiacSign << endl;
    os << "Birthday: " << obj.birthday[0] << "/" << obj.birthday[1] << "/" << obj.birthday[2] << endl;
    return os;
}

class Keeper {
private:
    SIGN** signs;
    int numSigns;

public:
    Keeper() {
        signs = new SIGN * [1];
        numSigns = 0;
    }

    void addSign(SIGN* sign) {
        SIGN** temp = new SIGN * [numSigns + 1];
        for (int i = 0; i < numSigns; i++) {
            temp[i] = signs[i];
        }
        temp[numSigns] = sign;
        delete[] signs;
        signs = temp;
        numSigns++;
    }

    void removeSign(int index) {
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

    void printSigns() {
        for (int i = 0; i < numSigns; i++) {
            cout << *signs[i] << endl;
        }
    }

    int getnumSigns() {
        return this->numSigns;
    }

    SIGN* getSign(int i) {
        return this->signs[i];
    }

    void sortByBirthDate() {
        sort(signs, signs + numSigns, [](SIGN* a, SIGN* b) {
            return compareSignDates(a, b);
            });
    }

    static bool compareSignDates(SIGN* a, SIGN* b) {
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
};


int main() {

    Keeper recordKeeper;


    recordKeeper.addSign(new SIGN("Doe", "John", "Aries", 5, 3, 1999));
    recordKeeper.addSign(new SIGN("Smith", "Jane", "Scorpio", 17, 8, 1995));
    recordKeeper.addSign(new SIGN("Smith", "Lilly", "Aries", 15, 8, 1995));
    recordKeeper.addSign(new SIGN("Smith", "Kate", "Leo", 16, 8, 1995));
    recordKeeper.sortByBirthDate();
    string name;
    recordKeeper.removeSign(2);
    for (int i = 0; i < recordKeeper.getnumSigns(); i++) {
        cout << *recordKeeper.getSign(i) << endl;
    }
    getchar();
    cout << "Enter name: ";
    cin >> name;

    bool found = false;
    for (int i = 0; i < recordKeeper.getnumSigns(); i++) {
        if (recordKeeper.getSign(i)->getFirstName() == name) {
            cout << *recordKeeper.getSign(i) << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No record found for " << name << endl;
    }

    return 0;
}