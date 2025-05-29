#include "Author.h"
#include <sstream>
#include <stdexcept>
#include <vector>

Author::Author(int id, const string& name) : id(id), name(name) {}

int Author::getId() const { return id; }
string Author::getName() const { return name; }

void Author::setName(const string& newName) { name = newName; }

string Author::toString() const {
    return to_string(id) + ";" + name;
}

Author Author::fromString(const string& line) {
    stringstream ss(line);
    string part;
    vector<string> tokens;

    while (getline(ss, part, ';')) {
        tokens.push_back(part);
    }

    if (tokens.size() != 2) {
        throw runtime_error("Incorrect format of the Author string.");
    }

    return Author(stoi(tokens[0]), tokens[1]);
}