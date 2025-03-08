#include <iostream>
using namespace std;

void swap(int &v1, int &v2) {
  int temp = v1;
  v1 = v2;
  v2 = temp;
}


void swap_v2(int *v1, int *v2) {
  int temp = *v1;
  *v1 = *v2;
  *v2 = temp;
}

int main() {
    int a = 10, b = 20;
    swap(a, b);
    std::cout << a << " " << b << std::endl;

    int a1 = 10, b1 = 20;
    swap_v2(&a1, &b1);
    std::cout << "v2: " << a1 << " " << b1 << std::endl;

    return 0;
}