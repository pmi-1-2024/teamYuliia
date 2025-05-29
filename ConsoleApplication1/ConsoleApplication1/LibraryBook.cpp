#include "LibraryBook.h"
#include <vector>
#include <sstream>
#include <stdexcept>
using namespace std;

LibraryBook::LibraryBook(int libraryId, int bookId, int quantity)
    : libraryId(libraryId), bookId(bookId), quantity(quantity) {}

int LibraryBook::getLibraryId() const { return libraryId; }
int LibraryBook::getBookId() const { return bookId; }
int LibraryBook::getQuantity() const { return quantity; }

void LibraryBook::setQuantity(int newQuantity) { quantity = newQuantity; }

string LibraryBook::toString() const {
    return to_string(libraryId) + ";" +
        to_string(bookId) + ";" +
        to_string(quantity);
}

LibraryBook LibraryBook::fromString(const string& line) {
    stringstream ss(line);
    string part;
    vector<string> tokens;

    while (getline(ss, part, ';')) {
        tokens.push_back(part);
    }

    if (tokens.size() != 3) {
        throw runtime_error("Invalid format of the LibraryBook string.");
    }

    return LibraryBook(
        stoi(tokens[0]),
        stoi(tokens[1]),
        stoi(tokens[2])
    );
}