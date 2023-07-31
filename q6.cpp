#include <iostream>
#include <string>
using namespace std;


class Book {
private:
    string title;
    string author;
    string isbn;

public:
    Book(string title, string author, string isbn)
        : title(title), author(author), isbn(isbn) {}

    bool operator==(const Book& other) const {
        return this->isbn == other.isbn;
    }

    bool operator!=(const Book& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << book.title << " by " << book.author << " (ISBN: " << book.isbn << ")";
        return os;
    }
};

int main() {
    Book book1("Math in college", "F. Serge Prologne", "8-1-0-x");
    Book book2("Harry Potter", "Harper Lee", "9-5-4-3");
    Book book3("", "F. Scott Fitzgerald", "3-1-4-0");

    cout << (book1 == book2) <<  endl;
    cout << (book1 == book3) <<  endl;
    cout << (book1 != book2) <<  endl;
    cout << (book1 != book3) <<  endl;

    std::cout << book1 << std::endl;
    return 0;
}