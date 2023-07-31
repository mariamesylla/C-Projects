#include <iostream>
#include <string>
using namespace std;

class Book {
    string ISBN_;
    string title_;
    string author_;
    int copyright_;
    bool checkedOut_;

public:
    Book(const string& ISBN, const string& title, const string& author, int copyright)
    : ISBN_(ISBN),  author_(author), copyright_(copyright), title_(title), checkedOut_(false) {}

    string getIsbn() const {return ISBN_; }
    string getTitle() const {return title_; }
    string getAuthor() const {return author_; }
    int getCopyright() const {return copyright_;}
    bool isCheckedOut() const {return checkedOut_; }

    void checkIn() { checkedOut_ = false; }
    void checkOut() {checkedOut_ = true;}

    bool validIsbn(const string& ISBN) {

        if (ISBN.length() != 5) {
            return false; 
        }

        for (int i = 0; i < 3; ++i) {
            if (!isdigit(ISBN[i])) {
                return false;
            }
        }
     
        if (ISBN[3] != '-') {
            return false;
        }
  
        if (!isalnum(ISBN[4])) {
            return false;
        }
     
      return true;
    }
};

int main() {
    

    Book book("539-A", "Foundations of Computer Science - 4th Edition", "Behrouz Forouzan", 2005);
    
    book.checkOut();

    cout << "Book ISBN: " << book.getIsbn() <<endl;
    cout << "Book Title: " << book.getTitle() << endl;
    cout << "The Author: " << book.getAuthor() << endl;
    cout << "Copyright: " << book.getCopyright() <<endl;
    cout << "Checked out: " << book.isCheckedOut() <<endl;
    
    book.checkIn();
    cout << "Checked In: " << book.isCheckedOut() << endl;
    cout << "Valid ISBN: " << book.validIsbn(book.getIsbn()) <<endl;
    cout << "Invalid ISBN: " << book.validIsbn("1-3-5-7") <<endl;

    return 0;
}
