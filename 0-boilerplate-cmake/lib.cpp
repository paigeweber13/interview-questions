//
// Created by Paige Riley Weber on 7/23/21.
//

#include "lib.hpp"

unsigned int Factorial( unsigned int number ) {
  return number <= 1 ? number : Factorial(number-1)*number;
}
