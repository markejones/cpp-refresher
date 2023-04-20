#include <iostream>

class Baddie {
  std::string _id;
  std::string _name;
  int hitPointsCurrent;
  /**
   * 1 = 100%
   */
  float hitPointsCurrentPct;
  int hitPointsMax;

public:
  Baddie(std::string name, int hitPointsMax);
  std::string getName() const;
  int getMaxHitPoints() const;
};

Baddie::Baddie(std::string name, int hitPointsMax) {
  _id = name;
  _name = name;
  this->hitPointsCurrent = hitPointsMax;
  this->hitPointsMax = hitPointsMax;
  this->hitPointsCurrentPct = 1;
}

std::string Baddie::getName() const {
  return this->_name;
}

int Baddie::getMaxHitPoints() const {
  return this->hitPointsMax;
}

std::ostream& operator<<(std::ostream& os, const Baddie& obj) {
  std::cout << "Baddie name is " << obj.getName() << " and their max hit points are " << obj.getMaxHitPoints() << std::endl;
  return os;
}

int main() {
  Baddie b("Clayface", 500);
  std::cout << b << std::endl;

  return 0;
}