
# Google Test (gtest)

#include <gtest/gtest.h>
#include "../include/Library.h"
#include "../include/AuthManager.h"
#include "../include/FineCalculator.h"

// UNIT TESTING


TEST(AuthUnitTest, ValidLogin)
{
    AuthManager auth;
    EXPECT_TRUE(auth.login("admin", "1234")); // matches regex
}

TEST(AuthUnitTest, InvalidUsername)
{
    AuthManager auth;
    EXPECT_FALSE(auth.login("wrong", "1234")); // username fails first
}

TEST(AuthUnitTest, InvalidPasswordAlpha)
{
    AuthManager auth;
    EXPECT_FALSE(auth.login("admin", "abcd")); // letters not allowed
}

TEST(AuthUnitTest, InvalidPasswordMixed)
{
    AuthManager auth;
    EXPECT_FALSE(auth.login("admin", "12ab")); // mixed invalid
}

TEST(AuthUnitTest, InvalidPasswordLengthShort)
{
    AuthManager auth;
    EXPECT_FALSE(auth.login("admin", "123")); // less than 4 digits
}

TEST(AuthUnitTest, InvalidPasswordLengthLong)
{
    AuthManager auth;
    EXPECT_FALSE(auth.login("admin", "12345")); // more than 4 digits
}

TEST(AuthUnitTest, EmptyCredentials)
{
    AuthManager auth;
    EXPECT_FALSE(auth.login("", ""));
}

// Library Module Tests
TEST(LibraryUnitTest, AddBook)
{
    Library lib;

    lib.addBook(Book(1, "C++"));

    EXPECT_EQ(lib.totalBooks(), 1);
}

TEST(LibraryUnitTest, AddMultipleBooks)
{
    Library lib;

    lib.addBook(Book(1, "C++"));
    lib.addBook(Book(2, "DSA"));
    lib.addBook(Book(3, "DBMS"));

    EXPECT_EQ(lib.totalBooks(), 3);
}

TEST(LibraryUnitTest, BorrowAvailableBook)
{
    Library lib;

    lib.addBook(Book(1, "C++"));

    EXPECT_TRUE(lib.borrowBook(1));
}

TEST(LibraryUnitTest, BorrowNonExistingBook)
{
    Library lib;

    EXPECT_FALSE(lib.borrowBook(100));
}

TEST(LibraryUnitTest, ReturnBook)
{
    Library lib;

    lib.addBook(Book(1, "OS"));
    lib.borrowBook(1);

    EXPECT_TRUE(lib.returnBook(1));
}

TEST(LibraryUnitTest, ReturnNonExistingBook)
{
    Library lib;

    EXPECT_FALSE(lib.returnBook(500));
}

// Fine Calculator Tests

TEST(FineUnitTest, ZeroLateDays)
{
    FineCalculator fine;

    EXPECT_EQ(fine.calculateFine(0), 0);
}

TEST(FineUnitTest, OneLateDay)
{
    FineCalculator fine;

    EXPECT_EQ(fine.calculateFine(1), 10);
}

TEST(FineUnitTest, FiveLateDays)
{
    FineCalculator fine;

    EXPECT_EQ(fine.calculateFine(5), 50);
}

TEST(FineUnitTest, NegativeLateDays)
{
    FineCalculator fine;

    EXPECT_EQ(fine.calculateFine(-1), 0);
}

TEST(FineUnitTest, LargeFineValue)
{
    FineCalculator fine;

    EXPECT_EQ(fine.calculateFine(100), 1000);
}

// INTEGRATION TESTING

TEST(IntegrationTest, LoginAndBorrowBook)
{
    AuthManager auth;
    Library lib;

    lib.addBook(Book(1, "C++"));

    bool loginResult = auth.login("admin", "1234");
    bool borrowResult = lib.borrowBook(1);

    EXPECT_TRUE(loginResult);
    EXPECT_TRUE(borrowResult);
}

TEST(IntegrationTest, BorrowAndReturnBook)
{
    Library lib;

    lib.addBook(Book(1, "Math"));

    bool borrowResult = lib.borrowBook(1);
    bool returnResult = lib.returnBook(1);

    EXPECT_TRUE(borrowResult);
    EXPECT_TRUE(returnResult);
}

TEST(IntegrationTest, BorrowBookAndCalculateFine)
{
    Library lib;
    FineCalculator fine;

    lib.addBook(Book(1, "Physics"));

    bool borrowResult = lib.borrowBook(1);
    double fineResult = fine.calculateFine(3);

    EXPECT_TRUE(borrowResult);
    EXPECT_EQ(fineResult, 30);
}

// SYSTEM TESTING

TEST(SystemTest, CompleteLibraryWorkflow)
{
    AuthManager auth;
    Library lib;
    FineCalculator fine;

    lib.addBook(Book(1, "C++"));
    lib.addBook(Book(2, "Java"));

    bool loginResult = auth.login("admin", "1234");
    bool borrowResult = lib.borrowBook(1);
    bool returnResult = lib.returnBook(1);
    double fineResult = fine.calculateFine(2);

    EXPECT_TRUE(loginResult);
    EXPECT_TRUE(borrowResult);
    EXPECT_TRUE(returnResult);
    EXPECT_EQ(fineResult, 20);
}

TEST(SystemTest, MultipleBookWorkflow)
{
    Library lib;

    lib.addBook(Book(1, "Book1"));
    lib.addBook(Book(2, "Book2"));
    lib.addBook(Book(3, "Book3"));

    EXPECT_TRUE(lib.borrowBook(1));
    EXPECT_TRUE(lib.borrowBook(2));
    EXPECT_TRUE(lib.returnBook(1));

    EXPECT_EQ(lib.totalBooks(), 3);
}

// ACCEPTANCE TESTING

TEST(AcceptanceTest, UserSuccessfullyBorrowsBook)
{
    AuthManager auth;
    Library lib;

    lib.addBook(Book(1, "Networking"));

    EXPECT_TRUE(auth.login("admin", "1234"));
    EXPECT_TRUE(lib.borrowBook(1));
}

TEST(AcceptanceTest, UserReturnsBookSuccessfully)
{
    Library lib;

    lib.addBook(Book(1, "AI"));

    lib.borrowBook(1);

    EXPECT_TRUE(lib.returnBook(1));
}

TEST(AcceptanceTest, UserViewsCorrectFine)
{
    FineCalculator fine;

    EXPECT_EQ(fine.calculateFine(7), 70);
}

TEST(SearchTest, ExistingBook)
{
    Library lib;
    Search search;

    EXPECT_TRUE(search.searchByTitle(lib, "C++"));
}

TEST(SearchTest, NonExistingBook)
{
    Library lib;
    Search search;

    EXPECT_FALSE(search.searchByTitle(lib, "Python"));
