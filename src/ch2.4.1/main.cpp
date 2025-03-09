#include <iostream>
using namespace std;

int main () {
	const int i = -1, &r = 0;
 	// 错误，非常量引用的初始值必须为左值（可以取地址）
    // int i = -1, &r = 0;

    // int i2 = 10;
    // int *const p2 = &i2;


}