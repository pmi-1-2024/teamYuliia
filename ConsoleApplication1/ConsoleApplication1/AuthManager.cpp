#include "AuthManager.h"
#include <algorithm>
#include <iostream>

User* AuthManager::login(const string& email, const string& password, const vector<User>& users) {
    for (const auto& user : users) {
        if (user.getEmail() == email && user.getPassword() == password) {
            return new User(user); // створюємо копію для сесії
        }
    }
    return nullptr;
}

bool AuthManager::emailExists(const string& email, const vector<User>& users) {
    return any_of(users.begin(), users.end(), [&](const User& u) {
        return u.getEmail() == email;
        });
}

User AuthManager::registerUser(const string& name, const string& email, const string& password, int defaultRoleId, vector<User>& users) {
    int newId = 1;
    if (!users.empty()) {
        newId = users.back().getId() + 1;
    }

    User newUser(newId, name, email, password, defaultRoleId);
    users.push_back(newUser);
    return newUser;
}