#include <iostream>
using namespace std;

class Book {
    string author;
    string title;
    double price;
    string publisher;
public:
    // Constructor
    Book(string a, string t, double p, string pub) 
        : author(a), title(t), price(p), publisher(pub) {}
    
    // Search function
    void search(string t, string a) {
        if (title == t && author == a) {
            cout << "Book found!\n";
            cout << "Title: " << title << "\nAuthor: " << author 
                 << "\nPrice: " << price << "\nPublisher: " << publisher << endl;
        } else {
            cout << "Book not found in inventory.\n";
        }
    }
};

int main() {
    Book inventory[] = {
        Book("J.K. Rowling", "Harry Potter", 499.99, "Bloomsbury"),
        Book("George Orwell", "1984", 299.50, "Secker & Warburg"),
        Book("Harper Lee", "To Kill a Mockingbird", 350.00, "J. B. Lippincott & Co.")
    };
    
    string title, author;
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    
    bool found = false;
    for (Book& b : inventory) {
        b.search(title, author);
    }
    
    return 0;
}

/*

Enter book title: Harry Potter
Enter author: J.K. Rowling
Book found!
Title: Harry Potter
Author: J.K. Rowling
Price: 499.99
Publisher: Bloomsbury
Book not found in inventory.
Book not found in inventory.

*/