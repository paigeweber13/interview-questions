#include <iostream>

#include "lib.hpp"

int main() {
  std::cout << "The factorials of the first ten numbers are:" << std::endl;
  for(int i = 0; i < 10; i++) {
    std::cout << "Factorial(" << i << ") == " << Factorial(i) << std::endl;
  }
  return 0;
}
