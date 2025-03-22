#include <iostream>
#include "mongoose.h"
#include "zlib.h"
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
  // 打印mongose版本
  std::cout << "mongoose version: " << MG_VERSION << std::endl;
  // 打印zlib版本
  std::cout << "zlib version: " << zlibVersion() << std::endl;
  return 0;
}

