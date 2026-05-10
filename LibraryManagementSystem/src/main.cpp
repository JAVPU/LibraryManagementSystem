
#include <iostream>
#include "../include/Library.h"
#include "../include/AuthManager.h"
#include "../include/FineCalculator.h"
#include "../include/Search.h"

using namespace std;

int main() {

    AuthManager auth;

    if(auth.login("admin","1234")) {
        cout << "Login Successful\n";
    }

    Library lib;

    lib.addBook(Book(1, "C++"));
    lib.addBook(Book(2, "DSA"));

    cout << "Books: " << lib.totalBooks() << endl;

    if(lib.borrowBook(1)) {
        cout << "Borrowed Successfully\n";
    }

    FineCalculator fine;
    cout << "Fine: " << fine.calculateFine(3);

     Search search;

    if(search.searchByTitle(lib, "C++"))
    {    
    cout << "Book Found\n";
   }
   else
   {  
    cout << "Book Not Found\n";
   }

    return 0;
}



