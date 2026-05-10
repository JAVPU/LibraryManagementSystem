
cmake_minimum_required(VERSION 3.10)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(main
    src/main.cpp
    src/Book.cpp
    src/AuthManager.cpp
    src/FineCalculator.cpp
    src/Library.cpp
)
