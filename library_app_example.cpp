#include <iostream>
#include <memory>
#include <vector>

class Book {
private:
  std::string id;
  std::string name;
  std::vector<std::string> pages;
  int currentPage = 0;

public:
  Book(std::string name, std::vector<std::string> pages);
  std::string getId();
  std::string getCurrentPage();
};

Book::Book(std::string name, std::vector<std::string> pages) {
  this->id = name;
  this->name = name;
  this->pages = pages;
}

std::string Book::getId() {
  return this->id;
}

std::string Book::getCurrentPage() {
  return this->pages.at(this->currentPage);
}

class Library {
private:
  std::vector<std::shared_ptr<Book>> books;
  std::string activeBook;

public:
  void addBook(std::shared_ptr<Book> b);
  void setActiveBook(std::string id);
  std::shared_ptr<Book> getActiveBook();
};

void Library::addBook(std::shared_ptr<Book> b) {
  // books.push_back(std::move(b));
  books.push_back(b);
}

void Library::setActiveBook(std::string id) {
  activeBook = id;
}

int main() {
  const std::vector<std::string> pages{"page 1", "page 2", "page 3"};
  const auto book1 = std::make_shared<Book>("Test book", pages);

  const auto library = std::make_unique<Library>();
  library->addBook(book1);

  std::cout << book1->getCurrentPage() << std::endl;

  return 0;
}