#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


#include "keeper.h"
#include "sign.h"
#include "Exception.h"

#include <iostream>
#include <fstream>
void showMenu() {
    std::cout << "\nMenu:\n"
        "1. Add new profile\n"
        "2. Delete profile by index\n"
        "3. Find profiles by zodiac sign\n"
        "4. Show all profiles\n"
        "5. Exit\n";
}





int main() {
    Keeper keeper;
    try {
        while (true) {
            showMenu();
            int choice;
            std::cout << "\nEnter your choice:\n";
            std::cin >> choice;
            switch (choice) {
            case 1: {
                string firstName;
                string lastName;
                string userSign;
                int day;
                int month;
                int year;

                cout << "Enter the first name" << endl;
                cin >> firstName;

                cout << "Enter the last name" << endl;
                cin >> lastName;

                cout << "Enter the user zodiac sign" << endl;
                cin >> userSign;

                cout << "Enter the user day month and year of birth" << endl;
                cin >> day >> month >> year;

                keeper.addSign(new SIGN(lastName, firstName, userSign, day, month, year));
                keeper.sortByBirthDate();
                break;
            }
            case 2: {
                int index;
                cout << "Enter the index:" << endl;
                cin >> index;
                keeper.removeSign(index);
                break;
            }
            case 3: {
                string zodiacSign;
                cout << "Enter zodiac sign:" << endl;
                cin >> zodiacSign;
                bool found = false;
                for (int i = 0; i < keeper.getnumSigns(); i++) {
                    if (keeper.getSign(i)->getZodiacSign() == zodiacSign) {
                        cout << *keeper.getSign(i) << endl;
                        found = true;
                    }
                }

                if (!found) {
                    cout << "No record found for " << zodiacSign << endl;
                }
                break;
            }
            case 4: {
                for (int i = 0; i < keeper.getnumSigns(); i++) {
                    cout << *keeper.getSign(i) << endl;
                }
                break;
                return 0;
            }
            case 5: {
                std::cout << "\nExiting...\n";
                return 0;
            }
            default:
                std::cout << "\nInvalid choice!\n";
                break;
            }
        }
    }
    catch (Exception e) {
        std::cout << "\nError: " << e << std::endl;
    }
    return 0;
}
