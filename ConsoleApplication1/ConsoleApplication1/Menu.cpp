#include "Menu.h"
#include "AuthManager.h"
#include <iostream>
using namespace std;

void Menu::showStartMenu() {
    cout << "\n===================================================================== LIBRARY SYSTEM =======================================================================\n";
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "0. Exit" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Eneter your choise: ";
}

/// Головна авторизаційна логіка (реєстрація/вхід)
User* Menu::authFlow(vector<User>& users, int defaultRoleId) {
    int choice;
    do {
        showStartMenu();
        cin >> choice;

        if (choice == 1) {
            string email, password;
            cout << "Email: ";
            cin >> email;
            cout << "Password: ";
            cin >> password;

            User* user = AuthManager::login(email, password, users);
            if (user != nullptr) {
                cout << "You are logged in. Welcome, " << user->getName() << "!" << endl;
                return user;
            }
            else {
                cout << "Error: Invalid login or password." << endl;
            }

        }
        else if (choice == 2) {
            string name, email, password;
            cout << "Name: ";
            cin.ignore(); getline(cin, name);
            cout << "Email: ";
            cin >> email;

            if (AuthManager::emailExists(email, users)) {
                cout << "A user with this email already exists." << endl;
                continue;
            }

            cout << "Password: ";
            cin >> password;

            User newUser = AuthManager::registerUser(name, email, password, defaultRoleId, users);
            cout << "Registration was successful. Please log in again." << endl;

        }
        else if (choice == 0) {
            cout << "Exit the program." << endl;
            return nullptr;
        }
        else {
            cout << "Wrong choice. Please try again." << endl;
        }

    } while (true);
}