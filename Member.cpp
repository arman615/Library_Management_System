#include "Member.h"

Member::Member(const std::string& name, const std::string& contactInfo)
    : name(name), contactInfo(contactInfo) {}

const std::string& Member::getName() const {
    return name;
}

const std::string& Member::getContactInfo() const {
    return contactInfo;
}

const std::vector<std::string>& Member::getBorrowedBooks() const {
    return borrowedBooks;
}

void Member::borrowBook(const std::string& bookTitle) {
    borrowedBooks.push_back(bookTitle);
}

void Member::returnBook(const std::string& bookTitle) {
    for (size_t i = 0; i < borrowedBooks.size(); i++) {
        if (borrowedBooks[i] == bookTitle) {
            borrowedBooks.erase(borrowedBooks.begin() + i);
            break;
        }
    }
}
