
# Testing Documentation

## 1. Unit Testing
Test individual modules:
- login()
- calculateFine()
- borrowBook()

## 2. Integration Testing
Test interaction:
- Library + Book

## 3. System Testing
Run full application from main.cpp

## 4. Acceptance Testing
User scenario:
- Login
- Borrow book
- Return book
- Generate fine

---

# AAA Pattern

## Arrange
Create objects

## Act
Call function

## Assert
Verify result

Example:
EXPECT_TRUE(auth.login("admin","1234"));

---

# Regular Expression Ideas
- Email validation
- Password validation
- ISBN validation

---

# User Defined Input/Output Pattern

Input:
Borrow Book ID

Output:
Success / Failed

---

# Boundary Value Analysis

| Input | Expected |
|------|------|
| -1 | Invalid |
| 0 | No Fine |
| 1 | Minimum Fine |
| 5 | Normal |
| 100 | Maximum Stress Test |

---

# doctest Syntax

TEST_CASE("Example") {
    CHECK(value == expected);
}

---

# gtest Syntax

TEST(TestSuite, TestName) {
    EXPECT_EQ(a,b);
    EXPECT_TRUE(condition);
}
