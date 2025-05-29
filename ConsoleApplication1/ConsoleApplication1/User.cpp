#include "User.h"
#include <vector>
#include <sstream>
#include <stdexcept>

User::User(int id, const string& name, const string& email, const string& password, int roleId)
    : id(id), name(name), email(email), password(password), roleId(roleId) {}

int User::getId() const { return id; }
string User::getName() const { return name; }
string User::getEmail() const { return email; }
string User::getPassword() const { return password; }
int User::getRoleId() const { return roleId; }

void User::setName(const string& newName) { name = newName; }
void User::setEmail(const string& newEmail) { email = newEmail; }
void User::setPassword(const string& newPassword) { password = newPassword; }
void User::setRoleId(int newRoleId) { roleId = newRoleId; }

string User::toString() const {
    return to_string(id) + ";" + name + ";" + email + ";" + password + ";" + to_string(roleId);
}

User User::fromString(const string& line) {
    stringstream ss(line);
    string part;
    vector<string> tokens;

    while (getline(ss, part, ';')) {
        tokens.push_back(part);
    }

    if (tokens.size() != 5) {
        throw runtime_error("Error: Invalid user string format.");
    }

    return User(stoi(tokens[0]), tokens[1], tokens[2], tokens[3], stoi(tokens[4]));
}