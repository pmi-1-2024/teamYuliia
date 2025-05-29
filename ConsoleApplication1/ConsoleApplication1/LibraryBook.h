#pragma once
#include <string>
using namespace std;

/// Клас LibraryBook — зв’язок між бібліотекою та книгою
class LibraryBook {
private:
    int libraryId;
    int bookId;
    int quantity;

public:
    LibraryBook() = default;
    LibraryBook(int libraryId, int bookId, int quantity);

    int getLibraryId() const;
    int getBookId() const;
    int getQuantity() const;

    void setQuantity(int newQuantity);

    string toString() const;
    static LibraryBook fromString(const string& line);
};