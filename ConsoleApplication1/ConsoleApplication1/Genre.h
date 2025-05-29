#pragma once
#include <string>
using namespace std;

/// Клас Genre — представляє жанр книги
class Genre {
private:
    int id;
    string name;

public:
    Genre() = default;
    Genre(int id, const string& name);

    int getId() const;
    string getName() const;

    void setName(const string& newName);

    string toString() const;
    static Genre fromString(const string& line);
};