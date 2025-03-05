#include <iostream>
using namespace std;

#include "zlib.h"

int main(void) {
  std::cout << "zlib version: " << zlibVersion() << std::endl;

  std::cout << "Hello, World!" << std::endl;
  return 0;
}