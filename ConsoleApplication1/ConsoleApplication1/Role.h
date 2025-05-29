#pragma once
#include <string>
using namespace std;

/// Клас Role — представляє роль користувача
class Role {
private:
    int id;
    string name;

public:
    Role() = default;
    Role(int id, const string& name);

    int getId() const;
    string getName() const;

    void setName(const string& newName);

    string toString() const;
    static Role fromString(const string& line);
};