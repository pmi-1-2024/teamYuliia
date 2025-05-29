#include "Order.h"
#include <vector>
#include <sstream>
#include <stdexcept>

Order::Order(int id, int userId, int bookId, const string& takeDate, const string& returnDate)
    : id(id), userId(userId), bookId(bookId), takeDate(takeDate), returnDate(returnDate) {}

int Order::getId() const { return id; }
int Order::getUserId() const { return userId; }
int Order::getBookId() const { return bookId; }
string Order::getTakeDate() const { return takeDate; }
string Order::getReturnDate() const { return returnDate; }

void Order::setReturnDate(const string& newDate) { returnDate = newDate; }

string Order::toString() const {
    return to_string(id) + ";" +
        to_string(userId) + ";" +
        to_string(bookId) + ";" +
        takeDate + ";" + returnDate;
}

Order Order::fromString(const string& line) {
    stringstream ss(line);
    string part;
    vector<string> tokens;

    while (getline(ss, part, ';')) {
        tokens.push_back(part);
    }

    if (tokens.size() != 5) {
        throw runtime_error("Incorrect format of the Order string.");
    }

    return Order(
        stoi(tokens[0]),  // id
        stoi(tokens[1]),  // userId
        stoi(tokens[2]),  // bookId
        tokens[3],        // takeDate
        tokens[4]         // returnDate
    );
}