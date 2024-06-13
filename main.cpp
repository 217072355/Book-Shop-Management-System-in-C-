#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // for std::setw

using namespace std;

// Define a class to represent a Book
class Book {
public:
    int id;
    string title;
    string author;
    double price;
    int stock;

    Book(int id, string title, string author, double price, int stock) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->price = price;
        this->stock = stock;
    }
};

// Define a class to manage the Book Shop
class BookShop {
private:
    vector<Book> books;

public:
    void addBook() {
        int id = books.size() + 1;
        string title, author;
        double price;
        int stock;

        cout << "\n";
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter book author: ";
        getline(cin, author);
        cout << "Enter book price: ";
        cin >> price;
        cout << "Enter stock quantity: ";
        cin >> stock;
        cout << "\n";


        books.push_back(Book(id, title, author, price, stock));
        cout << "Book added successfully!\n";
        cout << "\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the shop.\n";
            return;
        }

        cout << left << setw(5) << "ID" << setw(20) << "Title" << setw(20) << "Author" << setw(10) << "Price" << setw(10) << "Stock" << "\n";
        cout << "----------------------------------------------------------------\n";

        for (const auto& book : books) {
            cout << left << setw(5) << book.id << setw(20) << book.title << setw(20) << book.author << setw(10) << book.price << setw(10) << book.stock << "\n";
        }
    }

    void searchBookByTitle() {
        if (books.empty()) {
            cout << "No books available in the shop.\n";
            return;
        }

        string title;
        cout << "Enter book title to search: ";
        cin.ignore();
        getline(cin, title);

        bool found = false;
        for (const auto& book : books) {
            if (book.title == title) {
                cout << "Book found:\n";
                cout << "ID: " << book.id << "\n";
                cout << "Title: " << book.title << "\n";
                cout << "Author: " << book.author << "\n";
                cout << "Price: " << book.price << "\n";
                cout << "Stock: " << book.stock << "\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Book not found.\n";
        }
    }

    void purchaseBook() {
        if (books.empty()) {
            cout << "No books available in the shop.\n";
            return;
        }

        int id;
        cout << "Enter book ID to purchase: ";
        cin >> id;

        bool found = false;
        for (auto& book : books) {
            if (book.id == id) {
                if (book.stock > 0) {
                    book.stock--;
                    cout << "Book purchased successfully!\n";
                    cout << "Remaining stock: " << book.stock << "\n";
                } else {
                    cout << "Out of stock.\n";
                }
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Book not found.\n";
        }
    }
};

int main() {
    BookShop shop;
    int choice;

    while (true) {
        cout << "\nBook Shop Management System\n";
        cout << "\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by Title\n";
        cout << "4. Purchase Book\n";
        cout << "5. Exit\n";
        cout << "\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            shop.addBook();
            break;
        case 2:
            shop.displayBooks();
            break;
        case 3:
            shop.searchBookByTitle();
            break;
        case 4:
            shop.purchaseBook();
            break;
        case 5:
            cout << "\n";
            cout << "Thank you for using the Book Shop Management System. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
