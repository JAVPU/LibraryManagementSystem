
#pragma once
#include <vector>
#include "Book.h"

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(Book b);
    bool borrowBook(int id);
    bool returnBook(int id);
    int totalBooks();
};
