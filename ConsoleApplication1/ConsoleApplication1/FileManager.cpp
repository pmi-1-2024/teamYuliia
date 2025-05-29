#include "FileManager.h"
#include <fstream>
#include <iostream>
using namespace std;

template<typename T>
void saveToFile(const vector<T>& items, const string& filename) {
    ofstream out(filename);
    if (!out.is_open()) {
        cerr << "Error opening a file for writing: " << filename << endl;
        return;
    }
    for (const auto& item : items) {
        out << item.toString() << endl;
    }
    out.close();
}

template<typename T>
vector<T> loadFromFile(const string& filename) {
    vector<T> items;
    ifstream in(filename);
    if (!in.is_open()) {
        cerr << "Error opening a file for reading: " << filename << endl;
        return items;
    }

    string line;
    while (getline(in, line)) {
        try {
            items.push_back(T::fromString(line));
        }
        catch (const exception& e) {
            cerr << "Error processing a string: " << line << "\n" << e.what() << endl;
        }
    }

    in.close();
    return items;
}

void FileManager::saveUsersToFile(const vector<User>& users, const string& filename) {
    saveToFile(users, filename);
}
vector<User> FileManager::loadUsersFromFile(const string& filename) {
    return loadFromFile<User>(filename);
}

void FileManager::saveRolesToFile(const vector<Role>& roles, const string& filename) {
    saveToFile(roles, filename);
}
vector<Role> FileManager::loadRolesFromFile(const string& filename) {
    return loadFromFile<Role>(filename);
}

void FileManager::saveAuthorsToFile(const vector<Author>& authors, const string& filename) {
    saveToFile(authors, filename);
}
vector<Author> FileManager::loadAuthorsFromFile(const string& filename) {
    return loadFromFile<Author>(filename);
}

void FileManager::saveGenresToFile(const vector<Genre>& genres, const string& filename) {
    saveToFile(genres, filename);
}
vector<Genre> FileManager::loadGenresFromFile(const string& filename) {
    return loadFromFile<Genre>(filename);
}

void FileManager::savePublishersToFile(const vector<Publisher>& publishers, const string& filename) {
    saveToFile(publishers, filename);
}
vector<Publisher> FileManager::loadPublishersFromFile(const string& filename) {
    return loadFromFile<Publisher>(filename);
}

void FileManager::saveBooksToFile(const vector<Book>& books, const string& filename) {
    saveToFile(books, filename);
}
vector<Book> FileManager::loadBooksFromFile(const string& filename) {
    return loadFromFile<Book>(filename);
}

void FileManager::saveLibrariesToFile(const vector<Library>& libraries, const string& filename) {
    saveToFile(libraries, filename);
}
vector<Library> FileManager::loadLibrariesFromFile(const string& filename) {
    return loadFromFile<Library>(filename);
}

void FileManager::saveLibraryBooksToFile(const vector<LibraryBook>& items, const string& filename) {
    saveToFile(items, filename);
}
vector<LibraryBook> FileManager::loadLibraryBooksFromFile(const string& filename) {
    return loadFromFile<LibraryBook>(filename);
}

void FileManager::saveOrdersToFile(const vector<Order>& orders, const string& filename) {
    saveToFile(orders, filename);
}
vector<Order> FileManager::loadOrdersFromFile(const string& filename) {
    return loadFromFile<Order>(filename);
}