#pragma once
#include <string>
using namespace std;

/// Клас Order — представляє замовлення книги користувачем
class Order {
private:
    int id;
    int userId;
    int bookId;
    string takeDate;
    string returnDate; 

public:
    Order() = default;
    Order(int id, int userId, int bookId, const string& takeDate, const string& returnDate);

    int getId() const;
    int getUserId() const;
    int getBookId() const;
    string getTakeDate() const;
    string getReturnDate() const;

    void setReturnDate(const string& newDate);

    string toString() const;
    static Order fromString(const string& line);
};