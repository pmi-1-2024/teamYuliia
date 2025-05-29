#pragma once
#include <string>
using namespace std;

/// Клас User — представляє користувача системи
class User {
private:
    int id;
    string name;
    string email;
    string password;
    int roleId;

public:
    User() = default;
    User(int id, const string& name, const string& email, const string& password, int roleId);

    int getId() const;
    string getName() const;
    string getEmail() const;
    string getPassword() const;
    int getRoleId() const;

    void setName(const string& newName);
    void setEmail(const string& newEmail);
    void setPassword(const string& newPassword);
    void setRoleId(int newRoleId);

    string toString() const;
    static User fromString(const string& line);
};