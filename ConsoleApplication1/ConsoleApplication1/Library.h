#pragma once
#include <string>
using namespace std;

/// Клас Library — представляє бібліотеку
class Library {
private:
    int id;
    string name;
    string address;
    int durationDays; // Тривалість видачі книги в днях

public:
    Library() = default;
    Library(int id, const string& name, const string& address, int durationDays);

    int getId() const;
    string getName() const;
    string getAddress() const;
    int getDurationDays() const;

    void setName(const string& newName);
    void setAddress(const string& newAddress);
    void setDurationDays(int newDuration);

    string toString() const;
    static Library fromString(const string& line);
};