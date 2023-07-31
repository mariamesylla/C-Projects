#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    enum Genre { fiction, nonfiction, periodical, biography, children };

    Book(string title, string author, int year, Genre genre)
        : title(title), author(author), year(year), genre(genre) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }
    Genre getGenre() const { return genre; }

private:
    string title;
    string author;
    int year;
    Genre genre;
};

int main(){
    Book b1("National Geographic", "Many", 1998, Book::Genre::periodical);
    Book b2("Steve Jobs", "Walter Isaacson", 2009, Book::Genre::biography);
    Book b3("Where the Wild Things Are", "Maurice Sendak",2019, Book::Genre::children);

    cout << b1.getTitle() << " by " << b1.getAuthor() << " (" << static_cast<int>(b1.getGenre()) << ")" << endl;
    cout << b2.getTitle() << " by " << b2.getAuthor() << " (" << static_cast<int>(b2.getGenre()) << ")" << endl;
    cout << b3.getTitle() << " by " << b3.getAuthor() << " (" << static_cast<int>(b3.getGenre()) << ")" << endl;
 
    return 0;
}
