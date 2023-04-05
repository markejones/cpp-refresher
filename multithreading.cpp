#include <iostream>
#include <thread>

struct Damage {
  int incomingDamage;
  int blockedDamage;
};

void writeToDb(int hp) {
  std::cout << "Writing to db... this may take a while..." << std::endl;
  for (auto i = 0; i < 1000000; i++) {}
  std::cout << "Finished writing players new hp to db " << hp << std::endl;
}

void respondToUI(Damage d) {
  std::cout << "UI recieved result of attack on player" << std::endl;
  std::cout << "Damage recieved: " << d.incomingDamage << std::endl;
  std::cout << "Damage blocked: " << d.blockedDamage << std::endl;
}

// TODO:
int main() {

  std::cout << "Player gets attacked by ghoul" << std::endl;

  int playerHp = 100;
  int playerBlockValue = 3;
  int ghoulDamage = 10;
  int hp = playerHp - (ghoulDamage - playerBlockValue);
  std::thread dbThread(&writeToDb, hp);
  Damage d;
  d.blockedDamage = playerBlockValue;
  d.incomingDamage = ghoulDamage - playerBlockValue;
  std::thread uiThread(&respondToUI, d);

  dbThread.join();
  uiThread.join();
  return 0;
}