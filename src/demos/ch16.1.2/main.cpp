#include <iostream>
using namespace std;

template <typename T>
class Foo {
  T value;

  public:
    Foo(T v) : value(v) {}
    T get_value() const { return value; }
};


int main () {
  Foo<int> f(1);
  cout << f.get_value() << endl;



  return 0;
}