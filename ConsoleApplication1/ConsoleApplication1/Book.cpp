#include "Book.h"
#include <vector>
#include <sstream>
#include <stdexcept>

Book::Book(int id, const string& title, int year, int pages, int authorId, int genreId, int publisherId)
    : id(id), title(title), year(year), pages(pages),
    authorId(authorId), genreId(genreId), publisherId(publisherId) {}

int Book::getId() const { return id; }
string Book::getTitle() const { return title; }
int Book::getYear() const { return year; }
int Book::getPages() const { return pages; }
int Book::getAuthorId() const { return authorId; }
int Book::getGenreId() const { return genreId; }
int Book::getPublisherId() const { return publisherId; }

void Book::setTitle(const string& newTitle) { title = newTitle; }
void Book::setYear(int newYear) { year = newYear; }
void Book::setPages(int newPages) { pages = newPages; }
void Book::setAuthorId(int id) { authorId = id; }
void Book::setGenreId(int id) { genreId = id; }
void Book::setPublisherId(int id) { publisherId = id; }

string Book::toString() const {
    return to_string(id) + ";" + title + ";" + to_string(year) + ";" +
        to_string(pages) + ";" + to_string(authorId) + ";" +
        to_string(genreId) + ";" + to_string(publisherId);
}

Book Book::fromString(const string& line) {
    stringstream ss(line);
    string part;
    vector<string> tokens;

    while (getline(ss, part, ';')) {
        tokens.push_back(part);
    }

    if (tokens.size() != 7) {
        throw runtime_error("Incorrect format of the Book string.");
    }

    return Book(
        stoi(tokens[0]),    // id
        tokens[1],          // title
        stoi(tokens[2]),    // year
        stoi(tokens[3]),    // pages
        stoi(tokens[4]),    // authorId
        stoi(tokens[5]),    // genreId
        stoi(tokens[6])     // publisherId
    );
}