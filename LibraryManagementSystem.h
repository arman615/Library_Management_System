#ifndef LIBRARYMANAGEMENTSYSTEM_H
#define LIBRARYMANAGEMENTSYSTEM_H

#include "Book.h"
#include "Member.h"
#include <iostream>
#include <vector>

class LibraryManagementSystem {
private:
    std::vector<Book> books;
    std::vector<Member> members;

public:
    void registerBook(const std::string& title, const std::vector<std::string>& authors, const std::string& genre);
    void registerMember(const std::string& name, const std::string& contactInfo);
    void borrowBook(const std::string& memberName, const std::string& bookTitle);
    void returnBook(const std::string& memberName, const std::string& bookTitle);
    void generateOverdueReport();
    void searchBooks(const std::string& searchQuery);
};

#endif
