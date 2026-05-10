
# Library Management System (C++)

## Modules
1. Authentication Module
2. Book Management Module
3. Borrow/Return Module
4. Fine Calculation Module
5. Search Module

## Critical Modules for Testing
- Authentication → Security Critical
- Borrow/Return → Data Integrity Critical
- Fine Calculation → Financial Critical

## UML Diagrams for Sparx
Create:
- Class Diagram
- Activity Diagram
- Use Case Diagram

Main Classes:
- User
- AuthManager
- Book
- Library
- FineCalculator

## Codacy Metrics to Analyze
- Number of Functions
- Decision Statements
- for loops
- while loops
- Cyclomatic Complexity

## Frameworks Used
1. Google Test (gtest)
2. doctest

## Build Notes
You can open this in Visual Studio or CMake.

## Testing Types
- Unit Testing
- Integration Testing
- System Testing
- Acceptance Testing

## Boundary Value Examples
- Maximum borrow limit = 5
- Fine = 0 minimum
- Negative days invalid
