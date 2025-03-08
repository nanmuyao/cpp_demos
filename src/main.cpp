#include <iostream>
using namespace std;

// #include "zlib.h"

template <typename T>
T my_max(T a, T b) {
  if (a > b) {
    return a;
  } else {
  return b;
}
}


int main(void) {
  // std::cout << "zlib version: " << zlibVersion() << std::endl;

  std::cout << my_max(1, 2) << std::endl;

  return 0;
}
