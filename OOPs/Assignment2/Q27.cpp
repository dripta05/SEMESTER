#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Book class definition
class Book {
    string isbn;
    string title;
    string authors;
    int price;

public:
    // Constructor
    Book(string isbn, string title, string authors, int price)
        : isbn(isbn), title(title), authors(authors), price(price) {}

    // Getter methods
    string getIsbn() const { return isbn; }
    string getTitle() const { return title; }
    int getPrice() const { return price; }
};

// BookStore class definition
class BookStore {
    unordered_map<string, pair<Book, int>> books; // stores a pair of Book and number of copies

public:
    // Add a book to the bookstore
    void addBook(const Book& book, int copies) {
        books[book.getIsbn()] = make_pair(book, copies);
    }

    // Returns a list of unique ISBN numbers
    vector<string> getBooks() const {
        vector<string> isbnList;
        for (const auto& entry : books) {
            isbnList.push_back(entry.first);
        }
        return isbnList;
    }

    // Returns the number of copies for a given ISBN
    int noOfCopies(const string& isbn) const {
        auto it = books.find(isbn);
        if (it != books.end()) {
            return it->second.second;
        }
        return 0;
    }

    // Returns the total price of all books
    int totalPrice() const {
        int total = 0;
        for (const auto& entry : books) {
            total += entry.second.first.getPrice() * entry.second.second;
        }
        return total;
    }
};

// Main function
int main() {
    cout << "Enter number of books you want to register: " << endl;
    int n;
    cin >> n;

    BookStore store;

    for (int i = 0; i < n; i++) {
        string isbn, title, authors;
        int price, copies;

        cout << "Enter the ISBN number of book " << i + 1 << ": " << endl;
        cin >> isbn;
        cout << "Enter the title of book " << i + 1 << ": " << endl;
        cin.ignore(); // To ignore the leftover newline character
        getline(cin, title);
        cout << "Enter the authors of book " << i + 1 << ": " << endl;
        getline(cin, authors);
        cout << "Enter the price of book " << i + 1 << ": " << endl;
        cin >> price;
        cout << "Enter the number of copies of book " << i + 1 << ": " << endl;
        cin >> copies;

        Book book(isbn, title, authors, price);
        store.addBook(book, copies);
    }

    cout << "Total price of all books: " << store.totalPrice() << endl;

    // Print the number of copies for each book
    vector<string> isbns = store.getBooks();
    for (const string& isbn : isbns) {
        cout << "Number of copies of book with ISBN " << isbn << " is " << store.noOfCopies(isbn) << " - Title: " << store.getBooks() << endl;
    }

    return 0;
}
