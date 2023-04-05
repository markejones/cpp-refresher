#include <memory>
#include <iostream>

class Error {
private:
  int error_code;
public:
  Error(int error_code);
  int getErrorCode() const;
};

Error::Error(int error_code) {
  this->error_code = error_code;
}

int Error::getErrorCode() const {
  return this->error_code;
}

void log(const Error& err) {
  std::cout << "Logging error code: " << err.getErrorCode() << std::endl;
}

int main() {
  int firstValue = 3, secondValue = 5;
  int* ptr;

  ptr = &firstValue; // ptr = address of firstValue
  *ptr = 10; // assign 10 to value stored at address held in ptr (firstValue)
  ptr = &secondValue; // ptr = address of secondValue
  *ptr = 20; // assign 20 to value stored at address help in ptr (secondValue)
  std::cout << "firstValue: " << firstValue << std::endl;
  std::cout << "secondValue: " << secondValue << std::endl;

  auto err = std::make_unique<Error>(5);
  log(*err);

  return 0;
}