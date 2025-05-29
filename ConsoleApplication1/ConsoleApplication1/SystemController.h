#pragma once
#include "User.h"
#include "Role.h"
#include <vector>
using namespace std;

class SystemController {
public:
    static void run(User* currentUser, vector<User>& users, const vector<Role>& roles);
private:
    static void adminMenu(User* currentUser, vector<User>& users, const vector<Role>& roles);
    static void librarianMenu(User* currentUser);
    static void librarianBookMenu();
    static void librarianLibraryBookMenu();
    static void librarianOrderMenu();
    static void userMenu(User* currentUser);
};