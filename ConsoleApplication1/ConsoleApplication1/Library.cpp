#include "Library.h"
#include <vector>
#include <sstream>
#include <stdexcept>

Library::Library(int id, const string& name, const string& address, int durationDays)
    : id(id), name(name), address(address), durationDays(durationDays) {}

int Library::getId() const { return id; }
string Library::getName() const { return name; }
string Library::getAddress() const { return address; }
int Library::getDurationDays() const { return durationDays; }

void Library::setName(const string& newName) { name = newName; }
void Library::setAddress(const string& newAddress) { address = newAddress; }
void Library::setDurationDays(int newDuration) { durationDays = newDuration; }

string Library::toString() const {
    return to_string(id) + ";" + name + ";" + address + ";" + to_string(durationDays);
}

Library Library::fromString(const string& line) {
    stringstream ss(line);
    string part;
    vector<string> tokens;

    while (getline(ss, part, ';')) {
        tokens.push_back(part);
    }

    if (tokens.size() != 4) {
        throw runtime_error("Incorrect format of the Library string.");
    }

    return Library(
        stoi(tokens[0]),  // id
        tokens[1],        // name
        tokens[2],        // address
        stoi(tokens[3])   // durationDays
    );
}