#include "SystemController.h"
#include "FileManager.h"
#include "Book.h"
#include "LibraryBook.h"
#include "Library.h"
#include "Author.h"
#include "Genre.h"
#include "Publisher.h"
#include "Order.h"
#include "User.h"
#include <iostream>
#include <algorithm>
using namespace std;

void SystemController::run(User* currentUser,
    vector<User>& users,
    const vector<Role>& roles) {
    int roleId = currentUser->getRoleId();
    string roleName = "Unknown";

    for (const auto& role : roles) {
        if (role.getId() == roleId) {
            roleName = role.getName();
            break;
        }
    }

    cout << "\nYour role: " << roleName << "\n";

    if (roleName == "Administrator") {
        adminMenu(currentUser, users, roles);
    }
    else if (roleName == "Librarian") {
        librarianMenu(currentUser);
    }
    else if (roleName == "User") {
        userMenu(currentUser);
    }
    else {
        cout << "Unknown role. Exit." << endl;
    }
}

void SystemController::adminMenu(User* currentUser, vector<User>& users, const vector<Role>& roles) {
    int choice;
    do {
        cout << "\n================================================================= ADMINISTRATOR MAIN MENU ==================================================================\n";
        cout << "1. Show all users" << endl;
        cout << "2. Change the user role" << endl;
        cout << "3. Library management" << endl;
        cout << "0. Exit" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enetr your choice: ";
        cin >> choice;

        if (choice == 1) {
            for (const auto& user : users) {
                cout << "ID: " << user.getId() 
                    << " | Name: " << user.getName()
                    << " | Email: " << user.getEmail() 
                    << " | RoleID: " << user.getRoleId() << endl;
            }
        }
        else if (choice == 2) {
            int userId, newRoleId;
            cout << "Enter user ID: ";
            cin >> userId;
            cout << "Enter role ID: ";
            cin >> newRoleId;

            bool updated = false;
            for (auto& user : users) {
                if (user.getId() == userId) {
                    user.setRoleId(newRoleId);
                    cout << "Role updated." << endl;
                    updated = true;
                    break;
                }
            }
            if (!updated) {
                cout << "User with this ID was not found." << endl;
            }
        }
        else if (choice == 3) {
            vector<Library> libraries = FileManager::loadLibrariesFromFile("libraries.txt");

            int libChoice;
            do {
                cout << "\n==================================================================== Library Management ====================================================================\n";
                cout << "1. View all libraries" << endl;
                cout << "2. Add a library" << endl;
                cout << "3. Edit a library" << endl;
                cout << "4. Delete a library" << endl;
                cout << "0. Back" << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "Enter your choice: ";
                cin >> libChoice;

                if (libChoice == 1) {
                    for (const auto& lib : libraries) {
                        cout << "ID: " << lib.getId()
                            << " | Name: " << lib.getName()
                            << " | Address: " << lib.getAddress()
                            << " | Duration: " << lib.getDurationDays() << " days" << endl;
                    }

                }
                else if (libChoice == 2) {
                    int id = libraries.empty() ? 1 : libraries.back().getId() + 1;
                    string name, address;
                    int duration;

                    cin.ignore();
                    cout << "Library name: ";
                    getline(cin, name);
                    cout << "Library address: ";
                    getline(cin, address);
                    cout << "Loan duration (in days): ";
                    cin >> duration;

                    libraries.emplace_back(id, name, address, duration);
                    cout << "Library added." << endl;

                }
                else if (libChoice == 3) {
                    int id;
                    cout << "Enter library ID to edit: ";
                    cin >> id;

                    auto it = find_if(libraries.begin(), libraries.end(), [&](const Library& l) {
                        return l.getId() == id;
                        });

                    if (it != libraries.end()) {
                        string name, address;
                        int duration;
                        cin.ignore();
                        cout << "New name: ";
                        getline(cin, name);
                        cout << "New address: ";
                        getline(cin, address);
                        cout << "New duration (days): ";
                        cin >> duration;

                        it->setName(name);
                        it->setAddress(address);
                        it->setDurationDays(duration);

                        cout << "Library updated." << endl;
                    }
                    else {
                        cout << "Library not found." << endl;
                    }

                }
                else if (libChoice == 4) {
                    int id;
                    cout << "Enter library ID to delete: ";
                    cin >> id;

                    auto it = remove_if(libraries.begin(), libraries.end(), [&](const Library& l) {
                        return l.getId() == id;
                        });

                    if (it != libraries.end()) {
                        libraries.erase(it, libraries.end());
                        cout << "Library deleted." << endl;
                    }
                    else {
                        cout << "Library not found." << endl;
                    }

                }
                else if (libChoice == 0) {
                    break;
                }
                else {
                    cout << "Wrong choice." << endl;
                }

            } while (true);

            FileManager::saveLibrariesToFile(libraries, "libraries.txt");
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Wrong choice." << endl;
        }

    } while (true);
}

void SystemController::librarianMenu(User* currentUser) {
    int choice;
    do {
        cout << "\n=================================================================== LIBRARIAN MAIN MENU ====================================================================\n";
        cout << "1. Books" << endl;
        cout << "2. Books in libraries" << endl;
        cout << "3. Order" << endl;
        cout << "0. Exit" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            librarianBookMenu();
        }
        else if (choice == 2) {
            librarianLibraryBookMenu();
        }
        else if (choice == 3) {
            librarianOrderMenu();
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Wrong choice." << endl;
        }
    } while (true);
}

void SystemController::librarianBookMenu() {
    vector<Book> books = FileManager::loadBooksFromFile("books.txt");
    vector<Author> authors = FileManager::loadAuthorsFromFile("authors.txt");
    vector<Genre> genres = FileManager::loadGenresFromFile("genres.txt");
    vector<Publisher> publishers = FileManager::loadPublishersFromFile("publishers.txt");

    int choice;
    do {
        cout << "\n======================================================================= MENU: Books ========================================================================\n";
        cout << "1. View all books" << endl;
        cout << "2. Add a book" << endl;
        cout << "3. Delete a book" << endl;
        cout << "0. Back" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            for (const auto& book : books) {
                cout << "ID: " << book.getId() << " | Name: " << book.getTitle()
                    << " | AuthorID: " << book.getAuthorId()
                    << " | GenreID: " << book.getGenreId()
                    << " | PublisherID: " << book.getPublisherId()
                    << " | Year: " << book.getYear()
                    << " | Pages: " << book.getPages() << endl;
            }
        }
        else if (choice == 2) {
            int id = books.empty() ? 1 : books.back().getId() + 1;
            string title;
            int year, pages, authorId, genreId, publisherId;

            cin.ignore();
            cout << "Book title: ";
            getline(cin, title);
            cout << "Year of publication: ";
            cin >> year;
            cout << "Number of pages: ";
            cin >> pages;
            cout << "Author ID: ";
            cin >> authorId;
            cout << "Genre ID: ";
            cin >> genreId;
            cout << "Publisher ID: ";
            cin >> publisherId;

            books.emplace_back(id, title, year, pages, authorId, genreId, publisherId);
            cout << "Book added." << endl;
        }
        else if (choice == 3) {
            int id;
            cout << "ID of the book to be deleted: ";
            cin >> id;

            auto it = remove_if(books.begin(), books.end(), [&](const Book& b) {
                return b.getId() == id;
                });

            if (it != books.end()) {
                books.erase(it, books.end());
                cout << "The book has been deleted." << endl;
            }
            else {
                cout << "Book not found." << endl;
            }
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Wrong choice." << endl;
        }

    } while (true);

    FileManager::saveBooksToFile(books, "books.txt");
}

void SystemController::librarianLibraryBookMenu() {
    vector<LibraryBook> libraryBooks = FileManager::loadLibraryBooksFromFile("library_books.txt");

    int choice;
    do {
        cout << "\n================================================================= MENU: Books in libraries =================================================================\n";
        cout << "1. View all entries" << endl;
        cout << "2. Add a book to the library" << endl;
        cout << "3. Change the quantity" << endl;
        cout << "4. Delete a record" << endl;
        cout << "0. Back" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            for (const auto& lb : libraryBooks) {
                cout << "Library ID: " << lb.getLibraryId()
                    << " | Book ID: " << lb.getBookId()
                    << " | Quantity: " << lb.getQuantity() << endl;
            }
        }
        else if (choice == 2) {
            int libId, bookId, qty;
            cout << "Library ID: ";
            cin >> libId;
            cout << "Book ID: ";
            cin >> bookId;
            cout << "Quantity: ";
            cin >> qty;

            libraryBooks.emplace_back(libId, bookId, qty);
            cout << "Added." << endl;
        }
        else if (choice == 3) {
            int libId, bookId, newQty;
            cout << "Library ID: ";
            cin >> libId;
            cout << "Book ID: ";
            cin >> bookId;
            cout << "New quantity: ";
            cin >> newQty;

            bool found = false;
            for (auto& lb : libraryBooks) {
                if (lb.getLibraryId() == libId && lb.getBookId() == bookId) {
                    lb.setQuantity(newQty);
                    found = true;
                    cout << "Quantity updated." << endl;
                    break;
                }
            }
            if (!found) cout << "No record found." << endl;

        }
        else if (choice == 4) {
            int libId, bookId;
            cout << "Library ID: ";
            cin >> libId;
            cout << "Book ID: ";
            cin >> bookId;

            auto it = remove_if(libraryBooks.begin(), libraryBooks.end(), [&](const LibraryBook& lb) {
                return lb.getLibraryId() == libId && lb.getBookId() == bookId;
                });

            if (it != libraryBooks.end()) {
                libraryBooks.erase(it, libraryBooks.end());
                cout << "Record deleted." << endl;
            }
            else {
                cout << "Not found." << endl;
            }
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Wrong choice." << endl;
        }

    } while (true);

    FileManager::saveLibraryBooksToFile(libraryBooks, "library_books.txt");
}

void SystemController::librarianOrderMenu() {
    vector<Order> orders = FileManager::loadOrdersFromFile("orders.txt");

    int choice;
    do {
        cout << "\n======================================================================= MENU: Order ========================================================================\n";
        cout << "1. View all orders" << endl;
        cout << "2. Create a new order" << endl;
        cout << "3. Return the book" << endl;
        cout << "4. Delete an order" << endl;
        cout << "0. Back" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            for (const auto& order : orders) {
                cout << "ID: " << order.getId()
                    << " | UserID: " << order.getUserId()
                    << " | BookID: " << order.getBookId()
                    << " | Taken by: " << order.getTakeDate()
                    << " | Returned: " << order.getReturnDate() << endl;
            }

        }
        else if (choice == 2) {
            int id = orders.empty() ? 1 : orders.back().getId() + 1;
            int userId, bookId;
            string takeDate;

            cout << "User ID: ";
            cin >> userId;
            cout << "Book ID: ";
            cin >> bookId;
            cout << "Date of taking (YYYY-MM-DD): ";
            cin >> takeDate;

            orders.emplace_back(id, userId, bookId, takeDate, "");
            cout << "Order created." << endl;

        }
        else if (choice == 3) {
            int id;
            string returnDate;
            cout << "Order ID: ";
            cin >> id;
            cout << "Date of return (YYYY-MM-DD): ";
            cin >> returnDate;

            bool found = false;
            for (auto& order : orders) {
                if (order.getId() == id) {
                    order.setReturnDate(returnDate);
                    found = true;
                    cout << "The book has been returned." << endl;
                    break;
                }
            }
            if (!found) cout << "Order not found." << endl;

        }
        else if (choice == 4) {
            int id;
            cout << "Order ID for deletion: ";
            cin >> id;

            auto it = remove_if(orders.begin(), orders.end(), [&](const Order& o) {
                return o.getId() == id;
                });

            if (it != orders.end()) {
                orders.erase(it, orders.end());
                cout << "The order has been deleted." << endl;
            }
            else {
                cout << "Not found." << endl;
            }

        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Wrong choice." << endl;
        }

    } while (true);

    FileManager::saveOrdersToFile(orders, "orders.txt");
}

void SystemController::userMenu(User* currentUser) {
    vector<Book> books = FileManager::loadBooksFromFile("books.txt");
    vector<Author> authors = FileManager::loadAuthorsFromFile("authors.txt");
    vector<Genre> genres = FileManager::loadGenresFromFile("genres.txt");
    vector<Publisher> publishers = FileManager::loadPublishersFromFile("publishers.txt");
    vector<LibraryBook> libraryBooks = FileManager::loadLibraryBooksFromFile("library_books.txt");
    vector<Library> libraries = FileManager::loadLibrariesFromFile("libraries.txt");
    vector<Order> orders = FileManager::loadOrdersFromFile("orders.txt");

    int choice;
    do {
        cout << "\n======================================================================== USER MENU =========================================================================\n";
        cout << "1. View all books" << endl;
        cout << "2. View the availability of books in libraries" << endl;
        cout << "3. My order history" << endl;
        cout << "4. Get the book" << endl;
        cout << "5. Return the book" << endl;
        cout << "0. Exit" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            for (const auto& book : books) {
                cout << "ID: " << book.getId()
                    << " | Name: " << book.getTitle()
                    << " | Year: " << book.getYear()
                    << " | Pages: " << book.getPages()
                    << " | AuthorID: " << book.getAuthorId()
                    << " | GenreID: " << book.getGenreId()
                    << " | PublisherID: " << book.getPublisherId()
                    << endl;
            }

        }
        else if (choice == 2) {
            for (const auto& lb : libraryBooks) {
                cout << "ID library: " << lb.getLibraryId()
                    << " | Book ID: " << lb.getBookId()
                    << " | Quantity: " << lb.getQuantity() << endl;
            }

        }
        else if (choice == 3) {
            cout << "\n[Your orders]\n";
            for (const auto& order : orders) {
                if (order.getUserId() == currentUser->getId()) {
                    cout << "Order ID: " << order.getId()
                        << " | Book ID: " << order.getBookId()
                        << " | Taken by: " << order.getTakeDate()
                        << " | Returned: " << order.getReturnDate() << endl;
                }
            }
        }
        else if (choice == 4) {
            // Взяти книгу
            int bookId, libraryId;
            cout << "Book ID: ";
            cin >> bookId;
            cout << "Library ID ";
            cin >> libraryId;

            auto lbIt = find_if(libraryBooks.begin(), libraryBooks.end(), [&](const LibraryBook& lb) {
                return lb.getBookId() == bookId &&
                    lb.getLibraryId() == libraryId &&
                    lb.getQuantity() > 0;
                });

            if (lbIt != libraryBooks.end()) {
                lbIt->setQuantity(lbIt->getQuantity() - 1);
                int newId = orders.empty() ? 1 : orders.back().getId() + 1;
                string takeDate = "2025-05-21";

                orders.emplace_back(newId, currentUser->getId(), bookId, takeDate, "");
                cout << "The book was successfully taken." << endl;
            }
            else {
                cout << "The book is not available in this library or is missing." << endl;
            }

        }
        else if (choice == 5) {
            // Повернути книгу
            int orderId;
            cout << "Order ID: ";
            cin >> orderId;

            auto orderIt = find_if(orders.begin(), orders.end(), [&](const Order& o) {
                return o.getId() == orderId &&
                    o.getUserId() == currentUser->getId() &&
                    o.getReturnDate().empty();
                });

            if (orderIt != orders.end()) {
                orderIt->setReturnDate("2025-05-21");

                auto lbIt = find_if(libraryBooks.begin(), libraryBooks.end(), [&](const LibraryBook& lb) {
                    return lb.getBookId() == orderIt->getBookId();
                    });

                if (lbIt != libraryBooks.end()) {
                    lbIt->setQuantity(lbIt->getQuantity() + 1);
                }

                cout << "The book has been returned." << endl;
            }
            else {
                cout << "The active order was not found or has already been returned." << endl;
            }

        }
        else if (choice == 0) {
            break;

        }
        else {
            cout << "Wrong choice." << endl;
        }

    } while (true);

    FileManager::saveOrdersToFile(orders, "orders.txt");
    FileManager::saveLibraryBooksToFile(libraryBooks, "library_books.txt");
}