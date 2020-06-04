#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

class Book {
private:
    string name;
public:
    Book(string name) {
        this->name = name;
    }

    Book(const Book& boo) {
        this->name = boo.name;
    }

    string getName() {
        return this->name;
    }
};

class Iterator {
public:
    virtual bool hasNext() =0;
    virtual Book next() =0;
};

class Aggregate {
public:
    virtual Iterator * myIterator() =0;
    virtual ~Aggregate() {};
};

class BookShelfIterator;

class BookShelf :public Aggregate {
private:
    vector<Book> books;
public:

    void addBook(const Book& newbook) {
        books.push_back(newbook);
    }

    Book getBookAt(int index) {
        return books[index];
    }

    int getLength() {
        return books.size();
    }

    Iterator* myIterator();
    
};

class BookShelfIterator :public Iterator {
private:
    BookShelf bookShelf;
    int index;

public:
    BookShelfIterator(BookShelf newBookShelf) {
        this->bookShelf = newBookShelf;
        this->index = 0;
    }

    //ポインタを受け取った時のコンストラクタ
    //これがないとIterator *p = new MenuBookIterator(this);でエラー
    explicit BookShelfIterator(BookShelf* newBookShelf) {
        this->bookShelf = *newBookShelf;
        this->index = 0;
    }


    bool hasNext() {
        if (index < bookShelf.getLength()) {
            return true;
        }
        else {
            return false;
        }
    }

    Book next() override {
        Book book = bookShelf.getBookAt(index);
        index++;
        return book;
    }
};

Iterator* BookShelf::myIterator(){
    Iterator* p = new BookShelfIterator(this);
    return p;
    //return BookShelfIterator(this);
}


int main() {
    BookShelf *bookShelf = new BookShelf();

    bookShelf->addBook(Book("Git Hub"));
    bookShelf->addBook(Book("Qiita"));
    bookShelf->addBook(Book("Java"));
    bookShelf->addBook(Book("Iterator pattern"));

    Iterator* iterator = bookShelf->myIterator();

    while (iterator->hasNext()) {
        Book book = (Book)iterator->next();
        cout << book.getName() << endl;
    }
}


