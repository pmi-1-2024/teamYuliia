#pragma once
#include <string>
using namespace std;

/// Клас Publisher — представляє видавництво книги
class Publisher {
private:
    int id;
    string name;

public:
    Publisher() = default;
    Publisher(int id, const string& name);

    int getId() const;
    string getName() const;

    void setName(const string& newName);

    string toString() const;
    static Publisher fromString(const string& line);
};