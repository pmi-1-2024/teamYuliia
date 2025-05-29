#include "Genre.h"
#include <sstream>
#include <stdexcept>
#include <vector>

Genre::Genre(int id, const string& name) : id(id), name(name) {}

int Genre::getId() const { return id; }
string Genre::getName() const { return name; }

void Genre::setName(const string& newName) { name = newName; }

string Genre::toString() const {
    return to_string(id) + ";" + name;
}

Genre Genre::fromString(const string& line) {
    stringstream ss(line);
    string part;
    vector<string> tokens;

    while (getline(ss, part, ';')) {
        tokens.push_back(part);
    }

    if (tokens.size() != 2) {
        throw runtime_error("Incorrect format of the Genre string.");
    }

    return Genre(stoi(tokens[0]), tokens[1]);
}