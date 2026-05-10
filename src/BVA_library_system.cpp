#include <iostream>
#include <vector>

using namespace std;

/*AUTH TEST (Login Boundary) */

bool testLogin(string username, string password) {
    cout << "[Login Test] ";

    // Boundary: correct vs incorrect credentials
    if (username == "admin" && password == "1234") {
        cout << "VALID LOGIN " << endl;
        return true;
    } else {
        cout << "INVALID LOGIN " << endl;
        return false;
    }
}

/* FINE CALCULATOR  */
double calculateFine(int lateDays) {
    cout << "[Fine Test] lateDays = " << lateDays << " -> ";

    // Boundary: 0 (no fine), 1 (first penalty), negative (invalid)
    if (lateDays <= 0) {
        cout << "Fine = 0 " << endl;
        return 0;
    }

    double fine = lateDays * 10;
    cout << "Fine = " << fine << endl;
    return fine;
}

/* LIBRARY TESTS */
class LibraryTest {
    vector<int> books; 

public:
    void addBook(int id) {
        books.push_back(id);
    }

    bool borrowBook(int id) {
        cout << "[Borrow Test] Book ID " << id << " -> ";

        // Boundary: empty library / first book / invalid id
        for (int i = 0; i < books.size(); i++) {
            if (books[i] == id) {
                books[i] = -1; // borrowed
                cout << "BORROWED " << endl;
                return true;
            }
        }

        cout << "NOT FOUND " << endl;
        return false;
    }

    int totalBooks() {
        cout << "[Total Books] = " << books.size() << endl;
        return books.size();
    }
};

/* SEARCH TEST */
bool searchByTitle(string title) {
    cout << "[Search Test] title = " << title << " -> ";

    // Boundary idea: empty string, single char, valid title "C++"
    if (title == "C++") {
        cout << "FOUND " << endl;
        return true;
    }

    cout << "NOT FOUND " << endl;
    return false;
}
int main() {

    cout << " BOUNDARY VALUE ANALYSIS TESTS";

    /*LOGIN BVA */
    testLogin("admin", "1234");     // valid boundary
    testLogin("admin", "0000");     // invalid password
    testLogin("user", "1234");      // invalid username

    cout << "\n";

    /* FINE CALCULATOR BVA */
    calculateFine(-1);   // invalid boundary
    calculateFine(0);    // lower boundary
    calculateFine(1);    // just above boundary
    calculateFine(5);    // normal case

    cout << "\n";

    /*  LIBRARY BVA  */
    LibraryTest lib;
    lib.addBook(1);   // boundary: first book
    lib.addBook(2);   // second book

    lib.totalBooks();  // boundary: size check

    lib.borrowBook(1);  // valid borrow
    lib.borrowBook(3);  // invalid (not exists)

    cout << "\n";

    /*  SEARCH BVA  */
    searchByTitle("");        // empty boundary
    searchByTitle("C");       // single char boundary
    searchByTitle("C++");     // valid boundary


    return 0;
}