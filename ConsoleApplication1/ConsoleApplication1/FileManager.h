#pragma once
#include "User.h"
#include "Role.h"
#include "Author.h"
#include "Genre.h"
#include "Publisher.h"
#include "Book.h"
#include "Library.h"
#include "LibraryBook.h"
#include "Order.h"
#include <vector>
#include <string>
using namespace std;

/// Клас FileManager — обробка файлів
class FileManager {
public:
    // User
    static void saveUsersToFile(const vector<User>& users, const string& filename);
    static vector<User> loadUsersFromFile(const string& filename);

    // Role
    static void saveRolesToFile(const vector<Role>& roles, const string& filename);
    static vector<Role> loadRolesFromFile(const string& filename);

    // Author
    static void saveAuthorsToFile(const vector<Author>& authors, const string& filename);
    static vector<Author> loadAuthorsFromFile(const string& filename);

    // Genre
    static void saveGenresToFile(const vector<Genre>& genres, const string& filename);
    static vector<Genre> loadGenresFromFile(const string& filename);

    // Publisher
    static void savePublishersToFile(const vector<Publisher>& publishers, const string& filename);
    static vector<Publisher> loadPublishersFromFile(const string& filename);

    // Book
    static void saveBooksToFile(const vector<Book>& books, const string& filename);
    static vector<Book> loadBooksFromFile(const string& filename);

    // Library
    static void saveLibrariesToFile(const vector<Library>& libraries, const string& filename);
    static vector<Library> loadLibrariesFromFile(const string& filename);

    // FileManager
    static void saveLibraryBooksToFile(const vector<LibraryBook>& items, const string& filename);
    static vector<LibraryBook> loadLibraryBooksFromFile(const string& filename);

    //Order
    static void saveOrdersToFile(const vector<Order>& orders, const string& filename);
    static vector<Order> loadOrdersFromFile(const string& filename);
};