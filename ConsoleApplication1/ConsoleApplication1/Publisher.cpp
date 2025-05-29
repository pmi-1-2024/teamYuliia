#include "Publisher.h"
#include <vector>
#include <sstream>
#include <stdexcept>

Publisher::Publisher(int id, const string& name) : id(id), name(name) {}

int Publisher::getId() const { return id; }
string Publisher::getName() const { return name; }

void Publisher::setName(const string& newName) { name = newName; }

string Publisher::toString() const {
    return to_string(id) + ";" + name;
}

Publisher Publisher::fromString(const string& line) {
    stringstream ss(line);
    string part;
    vector<string> tokens;

    while (getline(ss, part, ';')) {
        tokens.push_back(part);
    }

    if (tokens.size() != 2) {
        throw runtime_error("Incorrect format of the Publisher string.");
    }

    return Publisher(stoi(tokens[0]), tokens[1]);
}