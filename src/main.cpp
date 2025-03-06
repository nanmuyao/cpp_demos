#include <iostream>
using namespace std;

#include "zlib.h"

template <typename T>
T max(T a, T b) {
  if (a > b) {
    return a;
  } else {
  return b;
}
}


int main(void) {
  std::cout << "zlib version: " << zlibVersion() << std::endl;

  std::cout << "abc" << std::endl;

  return 0;
}
