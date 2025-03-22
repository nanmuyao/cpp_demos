#include <iostream>
using namespace std;

struct Foo {
    int age;
    string name;
  /* data */
};

// 重载 << 操作符
std::ostream& operator<<(std::ostream& os, const Foo& foo) {
    os << "Foo(age: " << foo.age << ", name: " << foo.name << ")";
    return os;
}

struct Bar {
  int age;
  string name;
  /* data */
};



int main () {
  auto f = std::make_shared<Foo>();
  f->age = 1;
  f->name = "xiaode";

  std::cout << *f << std::endl;

  auto b = std::make_shared<Bar>();
  b->age = 2;
  b->name = "xiaode2";
  std::cout << *b << std::endl;

  return 0;
}