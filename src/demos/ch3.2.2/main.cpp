#include <iostream>
#include <typeinfo>

using namespace std;

void test_3_6() {
  string s = "hello world";

  for (auto &c : s) {
      c = 'X';
  }

  std::cout << "3_6:" << s << std::endl;
}


void test_3_7() {
  string s = "hello world";

  for (char c : s) {
      c = 'X';
  }

  std::cout << "3_7:" << s << std::endl;
}

void test_3_8() {
  string s = "hello world";
  for (int i = 0; i < s.size(); i++) {
    s[i] = 'X';
  }
  std::cout << "3.8:" << s << std::endl;
  
}

void test_3_9() {
  string s;
  cout << "access s with index" << s[0] << s[1] << endl;
}

string test_3_10() {
  string s;
  // cin >> s;
  std::cout << "请输入一句话" << endl;
  std::getline(std::cin, s);
  std::cout << "您输入的是：" << s << endl;
  
  if (s.empty()) {
    return string();
  }

  string tokens;
  vector<string> vec_string;
  // 输入中如果有标点符号，保留符号前的内容

  for (auto c : s) {
    if (ispunct(c)) {
      // 是符号
      vec_string.push_back(tokens);
      // tokens = "";
      tokens.clear();
    } else {
      // 不是符号
      tokens += c;
    }

  }
  if (!tokens.empty()) {
    vec_string.push_back(tokens);
    return vec_string.front();
  } else {
    return vec_string.front();
  }
}

void test_3_11() {
  const string s = "keep out!";
  for (auto &c : s) {
    c = 'a';
    cout << typeid(c).name() << endl;
  }

  string s1 = "keep out!";
  for (auto &c : s1) {
    c = 'a';
    cout << typeid(c).name() << endl;
  }
}

int main () {
  // string s = "hello world";
  // cout << s << s.size() << endl;
  // test_3_6();
  // test_3_7();

  // test_3_8();

  // test_3_9();
  // auto res = test_3_10();
  // cout << "input first seg: " << res << endl;


  test_3_11();
  return 0;
}