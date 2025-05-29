#pragma once
#include <string>
using namespace std;

/// Клас Author — представляє автора книги
class Author {
private:
    int id;
    string name;

public:
    Author() = default;
    Author(int id, const string& name);

    int getId() const;
    string getName() const;

    void setName(const string& newName);

    string toString() const;
    static Author fromString(const string& line);
};