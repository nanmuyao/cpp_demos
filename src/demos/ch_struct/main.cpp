#include <iostream>
#include <memory>

struct Example {
    int x;
    Example(int val) : x(val) { std::cout << "构造 Example(" << x << ")\n"; }
    ~Example() { std::cout << "析构 Example(" << x << ")\n"; }
};

int main() {
    std::shared_ptr<Example> ptr = std::make_shared<Example>(42);
    std::cout << "Example.x = " << ptr->x << std::endl;

    return 0;
} // 作用域结束，ptr 释放资源，调用 Example 的析构函数
