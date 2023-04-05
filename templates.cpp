#include <iostream>

template <class T>
T sum(T a, T b) {
  return a + b;
}

int main() {
  int a = 1;
  int b = 3;
  auto c = sum(a, b);

  double i = 10;
  double j = 15;
  auto k = sum(i, j);
  return 0;
}