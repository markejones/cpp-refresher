#include <iostream>
#include <vector>
#include <string>

bool isValidName(std::string _name) {
  if (_name.length() <= 10 && _name.length() >= 3) {
    return true;
  }

  return false;
}

std::string requestName() {
  std::string name = "";
  std::cout << "Please enter your character name" << std::endl;
  std::cin >> name;
  std::cout << "You typed: " << name << std::endl;
  return name;
}

int main() {
  const std::string message = "welcome to mmorpg character creation";
  std::cout << message << std::endl;

  std::string name = requestName();
  while (!isValidName(name)) {
    name = requestName();
  }

  std::cout << "name is valid: " << name << std::endl;

  return 1;
};