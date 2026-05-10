# doctest Framework 

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Library.h"
#include "../include/AuthManager.h"
#include "../include/FineCalculator.h"

// UNIT TESTS

TEST_CASE("Valid Login Regex")
{
    AuthManager auth;
    CHECK(auth.login("admin", "1234") == true);
}

TEST_CASE("Invalid Username")
{
    AuthManager auth;
    CHECK(auth.login("wrong", "1234") == false);
}

TEST_CASE("Password Not Numeric")
{
    AuthManager auth;
    CHECK(auth.login("admin", "abcd") == false);
}

TEST_CASE("Password Mixed Characters")
{
    AuthManager auth;
    CHECK(auth.login("admin", "12ab") == false);
}

TEST_CASE("Password Too Short")
{
    AuthManager auth;
    CHECK(auth.login("admin", "123") == false);
}

TEST_CASE("Password Too Long")
{
    AuthManager auth;
    CHECK(auth.login("admin", "12345") == false);
}

TEST_CASE("Empty Credentials")
{
    AuthManager auth;
    CHECK(auth.login("", "") == false);
}
TEST_CASE("Add Book")
{
    Library lib;

    lib.addBook(Book(1, "C++"));

    CHECK(lib.totalBooks() == 1);
}

TEST_CASE("Borrow Book")
{
    Library lib;

    lib.addBook(Book(1, "DSA"));

    CHECK(lib.borrowBook(1) == true);
}

TEST_CASE("Return Book")
{
    Library lib;

    lib.addBook(Book(1, "OS"));

    lib.borrowBook(1);

    CHECK(lib.returnBook(1) == true);
}

TEST_CASE("Fine Calculation")
{
    FineCalculator fine;

    CHECK(fine.calculateFine(5) == 50);
}

// INTEGRATION TESTS

TEST_CASE("Login And Borrow Integration")
{
    AuthManager auth;
    Library lib;

    lib.addBook(Book(1, "DBMS"));

    CHECK(auth.login("admin", "1234") == true);
    CHECK(lib.borrowBook(1) == true);
}

TEST_CASE("Borrow And Return Integration")
{
    Library lib;

    lib.addBook(Book(1, "Math"));

    CHECK(lib.borrowBook(1) == true);
    CHECK(lib.returnBook(1) == true);
}

// SYSTEM TESTS

TEST_CASE("Complete System Workflow")
{
    AuthManager auth;
    Library lib;
    FineCalculator fine;

    lib.addBook(Book(1, "Physics"));

    CHECK(auth.login("admin", "1234") == true);
    CHECK(lib.borrowBook(1) == true);
    CHECK(lib.returnBook(1) == true);
    CHECK(fine.calculateFine(3) == 30);
}

// ACCEPTANCE TESTS

TEST_CASE("Student Borrows Book Successfully")
{
    Library lib;

    lib.addBook(Book(1, "English"));

    CHECK(lib.borrowBook(1) == true);
}

# AAA Pattern Example


TEST(LibraryAAA, BorrowBook)
{
    // Arrange
    Library lib;
    lib.addBook(Book(1, "C++"));

    // Act
    bool result = lib.borrowBook(1);

    // Assert
    EXPECT_TRUE(result);
}

TEST_CASE("Search Existing Book")
{
    Library lib;
    Search search;

    CHECK(search.searchByTitle(lib, "C++") == true);
}

TEST_CASE("Search Non Existing Book")
{
    Library lib;
    Search search;

    CHECK(search.searchByTitle(lib, "Python") == false);
}

