#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string title;
    string author;
    string publisher;

public:

    Book(string t, string a, string p) 
        : title(t), author(a), publisher(p) {}

    virtual void display() const {
        cout << "=== Book Details ===" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
    }

    virtual ~Book() {}
};

class FictionBook : public Book {
private:
    string genre;
    string protagonist;

public:
    FictionBook(string t, string a, string p, string g, string pro)
        : Book(t, a, p), genre(g), protagonist(pro) {}

    void display() const override {
        cout << "\n=== Fiction Book Details ===" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Genre: " << genre << endl;
        cout << "Protagonist: " << protagonist << endl;
    }
};

int main() {

    FictionBook myBook("The Mysterious Manor", "Agatha Christie", 
                       "Penguin Books", "Mystery", "Hercule Poirot");
    myBook.display();
    return 0;
}
