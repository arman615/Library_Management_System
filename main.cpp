#include "LibraryManagementSystem.h"

int main() {
    LibraryManagementSystem libraryManagementSystem;

    libraryManagementSystem.registerBook("Book Title 1", {"Author 1", "Author 2"}, "Genre 1");
    libraryManagementSystem.registerBook("Book Title 2", {"Author 3"}, "Genre 2");

    libraryManagementSystem.registerMember("Arman Poghosyan", "armanpogh@mail.ru);
    libraryManagementSystem.registerMember("Bob Smith", "bsmith@gmail.com");

    libraryManagementSystem.borrowBook("Bob Smith", "Book Title 1");
    libraryManagementSystem.borrowBook("Bob Smith", "Book Title 2");

    libraryManagementSystem.returnBook("Bob Smith", "Book Title 1");

    libraryManagementSystem.generateOverdueReport();

    libraryManagementSystem.searchBooks("Genre 1");

    return 0;
}
