#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

class Book {
private:
    std::string title;
    std::vector<std::string> authors;
    std::string genre;
    bool available;

public:
    Book(const std::string& title, const std::vector<std::string>& authors, const std::string& genre);

    const std::string& getTitle() const;
    const std::vector<std::string>& getAuthors() const;
    const std::string& getGenre() const;
    bool isAvailable() const;
    void borrowBook();
    void returnBook();
};

#endif
