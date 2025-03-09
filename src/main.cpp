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

int main() {
  int v1, v2;

  std::cout << "enter two number:" << std::endl;
  std::cin >> v1 >> v2;

  std::cout << v1 + v2 << std::endl;

  return 0;
}


// int main(void) {
//   // std::cout << "zlib version: " << zlibVersion() << std::endl;

//   std::cout << my_max(1, 2) << std::endl;

//   return 0;
// }
