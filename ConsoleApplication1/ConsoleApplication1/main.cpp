#include <iostream>
#include <vector>
#include "User.h"
#include "Role.h"
#include "FileManager.h"
#include "Menu.h"
#include "SystemController.h"
using namespace std;

int main() {
    // Зчитування користувачів і ролей
    vector<User> users = FileManager::loadUsersFromFile("users.txt");
    vector<Role> roles = FileManager::loadRolesFromFile("roles.txt");

    // Авторизація / Реєстрація
    User* currentUser = Menu::authFlow(users, 3); // 3 — ID ролі "Користувач"

    // Якщо користувач увійшов — передати керування
    if (currentUser) {
        SystemController::run(currentUser, users, roles);
        delete currentUser;
    }

    // Збереження після виходу
    FileManager::saveUsersToFile(users, "users.txt");

    return 0;
}