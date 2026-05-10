
#include "../include/Library.h"

void Library::addBook(Book b) {
    books.push_back(b);
}

bool Library::borrowBook(int id) {
    for(auto &book : books) {
        if(book.id == id) {
            if(book.available) {
                book.available = false;
                return true;
            }
        }
    }
    return false;
}

bool Library::returnBook(int id) {
    for(auto &book : books) {
        if(book.id == id) {
            book.available = true;
            return true;
        }
    }
    return false;
}

int Library::totalBooks() {
    return books.size();
}
