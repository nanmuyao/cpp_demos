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

// int main() {
//     int a = 10, b = 20;
//     swap(a, b);
//     std::cout << a << " " << b << std::endl;

//     int a1 = 10, b1 = 20;
//     swap_v2(&a1, &b1);
//     std::cout << "v2: " << a1 << " " << b1 << std::endl;

//     return 0;
// }

int main1() {
    int *p = nullptr;

    
    std::cout << p << std::endl;
    // 格式化输出p 会把p的值转换为十六进制， 并影响后续的输出
    std::cout << std::hex << p << std::endl;

    int a = 10;
    int *p1 = &a;
    std::cout << p1 << std::endl;
    std::cout << *p1 << std::endl;
    std::cout << "end" << std::endl;
    return 0;
} 

int main2() {
    int i = 42;
    int *p1 = &i;
    *p1 = *p1 * *p1;
    p1 = nullptr;

    if (p1 != nullptr) {
      std::cout << *p1 << std::endl;
    } else {
      std::cout << "p1 is nullptr" << std::endl;
    }
    std::cout << i << std::endl;
    return 0;
} 

int main () {
	int i = 0;
	int *pi = &i;

	if (pi) {
		std::cout << "pi is not nullptr" << std::endl;
	} else {
		std::cout << "pi is nullptr" << std::endl;
	}
	
	return 0;
}