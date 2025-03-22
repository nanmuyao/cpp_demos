#include <iostream>

using namespace std;
// 1,    2, 3
// begin      end

// 1, 2, 3, 4
// b          e
// e - b = 4 / 2 == 2

void foo() {
  string s = "hello world";
  cout << *s.begin() << endl;
  cout << *(s.end() - 1 )<< endl;
}

int half_find(vector<int> &v, int find_v) {
  auto b = v.begin();
  auto e = v.end();

  while (b < e) {
    auto mid = b + (e - b) / 2;
    if ((*mid) < find_v) {
      b = mid + 1;
    } else if ((*mid) > find_v) {
      e = mid - 1;
    } else {
      return find_v;
    }
  }
  return 0;
}

int main () {

  vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  auto r = half_find(vi, 3);

  cout << r << endl;

}