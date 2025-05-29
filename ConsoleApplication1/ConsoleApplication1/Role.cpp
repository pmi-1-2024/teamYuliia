#include "Role.h"
#include <sstream>
#include <stdexcept>
#include <vector>

Role::Role(int id, const string& name) : id(id), name(name) {}

int Role::getId() const { return id; }
string Role::getName() const { return name; }

void Role::setName(const string& newName) { name = newName; }

string Role::toString() const {
    return to_string(id) + ";" + name;
}

Role Role::fromString(const string& line) {
    stringstream ss(line);
    string part;
    vector<string> tokens;

    while (getline(ss, part, ';')) {
        tokens.push_back(part);
    }

    if (tokens.size() != 2) {
        throw runtime_error("Incorrect format of the Role string.");
    }

    return Role(stoi(tokens[0]), tokens[1]);
}