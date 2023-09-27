#include "LibraryManagementSystem.h"

void LibraryManagementSystem::registerBook(const std::string& title, const std::vector<std::string>& authors, const std::string& genre) {
    Book newBook(title, authors, genre);
    books.push_back(newBook);
    std::cout << "Book registered successfully.\n";
}

void LibraryManagementSystem::registerMember(const std::string& name, const std::string& contactInfo) {
    Member newMember(name, contactInfo);
    members.push_back(newMember);
    std::cout << "Member registered successfully.\n";
}

void LibraryManagementSystem::borrowBook(const std::string& memberName, const std::string& bookTitle) {
    Member* memberPtr = nullptr;
    for (size_t i = 0; i < members.size(); i++) {
        if (members[i].getName() == memberName) {
            memberPtr = &members[i];
            break;
        }
    }
    if (memberPtr == nullptr) {
        std::cout << "Member not found.\n";
        return;
    }

    Book* bookPtr = nullptr;
    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getTitle() == bookTitle) {
            bookPtr = &books[i];
            break;
        }
    }
    if (bookPtr == nullptr) {
        std::cout << "Book not found.\n";
        return;
    }

    if (!bookPtr->isAvailable()) {
        std::cout << "Book is already borrowed.\n";
        return;
    }

    bookPtr->borrowBook();
    memberPtr->borrowBook(bookTitle);
    std::cout << "Book borrowed successfully.\n";
}

void LibraryManagementSystem::returnBook(const std::string& memberName, const std::string& bookTitle) {
    Member* memberPtr = nullptr;
    for (size_t i = 0; i < members.size(); i++) {
        if (members[i].getName() == memberName) {
            memberPtr = &members[i];
            break;
        }
    }
    if (memberPtr == nullptr) {
        std::cout << "Member not found.\n";
        return;
    }

    Book* bookPtr = nullptr;
    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getTitle() == bookTitle) {
            bookPtr = &books[i];
            break;
        }
    }
    if (bookPtr == nullptr) {
        std::cout << "Book not found.\n";
        return;
    }

    if (bookPtr->isAvailable()) {
        std::cout << "Book is not borrowed.\n";
        return;
    }

    bookPtr->returnBook();
    memberPtr->returnBook(bookTitle);
    std::cout << "Book returned successfully.\n";
}

void LibraryManagementSystem::generateOverdueReport() {
    std::cout << "Overdue Report\n";
    for (size_t i = 0; i < members.size(); i++) {
        const Member& member = members[i];
        for (size_t j = 0; j < member.getBorrowedBooks().size(); j++) {
            const std::string& bookTitle = member.getBorrowedBooks()[j];
            for (size_t k = 0; k < books.size(); k++) {
                const Book& book = books[k];
                if (book.getTitle() == bookTitle && !book.isAvailable()) {
                    std::cout << "Member: " << member.getName() << ", Book: " << bookTitle << std::endl;
                    break;
                }
            }
        }
    }
    std::cout << "--------------------------\n";
}

void LibraryManagementSystem::searchBooks(const std::string& searchQuery) {
    std::cout << "Search Results\n";
    for (size_t i = 0; i < books.size(); i++) {
        const Book& book = books[i];
        if (book.getTitle().find(searchQuery) != std::string::npos ||
            book.getGenre().find(searchQuery) != std::string::npos) {
            std::cout << "Title: " << book.getTitle() << ", Author(s): ";
            for (size_t j = 0; j < book.getAuthors().size(); j++) {
                std::cout << book.getAuthors()[j] << ", ";
            }
            std::cout << "Genre: " << book.getGenre() << ", Available: " << (book.isAvailable() ? "Yes" : "No") << std::endl;
        }
    }
    std::cout << "--------------------------\n";
}
