#pragma once
#include <string>
using namespace std;

/// Клас Book — представляє книгу
class Book {
private:
    int id;
    string title;
    int year;
    int pages;

    int authorId;
    int genreId;
    int publisherId;

public:
    Book() = default;
    Book(int id, const string& title, int year, int pages, int authorId, int genreId, int publisherId);

    int getId() const;
    string getTitle() const;
    int getYear() const;
    int getPages() const;
    int getAuthorId() const;
    int getGenreId() const;
    int getPublisherId() const;

    void setTitle(const string& newTitle);
    void setYear(int newYear);
    void setPages(int newPages);
    void setAuthorId(int id);
    void setGenreId(int id);
    void setPublisherId(int id);

    string toString() const;
    static Book fromString(const string& line);
};