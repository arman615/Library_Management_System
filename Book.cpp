#include "Book.h"

Book::Book(const std::string& title, const std::vector<std::string>& authors, const std::string& genre)
    : title(title), authors(authors), genre(genre), available(true) {}

const std::string& Book::getTitle() const {
    return title;
}

const std::vector<std::string>& Book::getAuthors() const {
    return authors;
}

const std::string& Book::getGenre() const {
    return genre;
}

bool Book::isAvailable() const {
    return available;
}

void Book::borrowBook() {
    available = false;
}

void Book::returnBook() {
    available = true;
}
