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
        "5. Edit profile by index\n"
        "6. Exit\n";
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
                if (index < keeper.getnumSigns())
                    keeper.removeSign(index);
                else
                    cout << "Invalid index!" << endl;
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
            }
            case 5: {
                int index;
                cout << "Enter the index:" << endl;
                cin >> index;
                if (index < keeper.getnumSigns()) {
                    SIGN &profile = *keeper.getSign(index);

                    string updatedFirstName;
                    cout << "Enter new first name (or enter No to not change): ";
                    cin >> updatedFirstName;

                    if (!(updatedFirstName == "No")) {
                        profile.setFirstName(updatedFirstName);
                    }

                    string updatedLastName;
                    cout << "Enter new last name (or enter No to not change): ";
                    cin >> updatedLastName;

                    if (!(updatedLastName == "No")) {
                        profile.setLastName(updatedLastName);
                    }

                    string zodiacSign;
                    cout << "Enter new zodiac sign (or enter No to not change): ";
                    cin >> zodiacSign;

                    if (!(zodiacSign == "No")) {
                        profile.setZodiacSign(zodiacSign);
                    }

                    int day;
                    int month;
                    int year;

                    cout << "Enter new birthday date (enter -1 -1 -1 to not change): ";
                    cin >> day >> month >> year;

                    if (!(day == -1 || month == -1 || year == -1))
                        profile.setBirthday(day, month, year);

                    keeper.setSign(&profile, index);
                }
                else
                    cout << "Invalid index!" << endl;
                break;
            }
            case 6: {
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
