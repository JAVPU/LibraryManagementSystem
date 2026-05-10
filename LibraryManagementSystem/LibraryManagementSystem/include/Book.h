
#pragma once
#include <string>

class Book {
public:
    int id;
    std::string title;
    bool available;

    Book(int i, std::string t);
};
