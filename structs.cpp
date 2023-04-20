#include <iostream>

enum class colour { red, green, pink };

struct apple {
  float weight;
  colour C;
};

// struct {
//   float w;
//   colour c;
// } apple;



int main() {
  apple pinkLady;
  pinkLady.C = colour::pink;
  pinkLady.weight = 34.5;

  std::cout << "Apple weighs (grams) " << pinkLady.weight << std::endl;
  return 0;
}