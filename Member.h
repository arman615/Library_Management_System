#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>

class Member {
private:
    std::string name;
    std::string contactInfo;
    std::vector<std::string> borrowedBooks;

public:
    Member(const std::string& name, const std::string& contactInfo);

    const std::string& getName() const;
    const std::string& getContactInfo() const;
    const std::vector<std::string>& getBorrowedBooks() const;
    void borrowBook(const std::string& bookTitle);
    void returnBook(const std::string& bookTitle);
};

#endif
