#include <iostream>
using namespace std;

class HasPtr {
    public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }

    std::string* get_ps() {
        return ps;
    }
    private:
    std::string *ps;
    int i;
};

int main1() {
    HasPtr hp("hi");
    HasPtr hp2 = hp;

    
    // 指针指向的是同一个地址 
    cout << "hp ps: " << *(hp.get_ps()) << endl;
    cout << "hp2 ps: " << *(hp2.get_ps()) << endl;


    cout << "hp ps: " << (hp.get_ps()) << endl;
    cout << "hp2 ps: " << (hp2.get_ps()) << endl;

    string* addr = hp.get_ps();
    cout << "addr: " << *addr << endl;

    // 打印ps的地址
    auto ps = hp.get_ps();
    cout << "ps addr: " << &ps << endl;

    auto ps2 = hp2.get_ps();
    cout << "ps addr: " << &ps2 << endl;
    return 0;
}



int main2() {
    HasPtr hp("hi");
    HasPtr hp2 = hp;

    
    // 指针指向的是同一个地址 
    cout << "hp ps: " << *(hp.get_ps()) << endl;
    cout << "hp2 ps: " << *(hp2.get_ps()) << endl;


    cout << "hp ps: " << (hp.get_ps()) << endl;
    cout << "hp2 ps: " << (hp2.get_ps()) << endl;

    string* addr = hp.get_ps();
    cout << "addr: " << *addr << endl;

    // 打印ps本身的地址
    auto ps = hp.get_ps();
    cout << "ps addr: " << &ps << endl;

    auto ps2 = hp2.get_ps();
    cout << "ps addr: " << &ps2 << endl;

    // 修改ph的值ph2的值也会改变
    *ps = "hi2";
    cout << "hp ps: " << *(hp.get_ps()) << endl;
    cout << "hp2 ps: " << *(hp2.get_ps()) << endl;
    return 0;
}

class HasPtr2 {
    public:

    HasPtr2(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }

    // 拷贝构造函数
    HasPtr2(const HasPtr2 &p):
        ps(new std::string(*p.ps)), i(p.i) { }

    std::string* get_ps() {
        return ps;
    }
    private:
    std::string *ps;
    int i;
};

int main() {
    HasPtr2 hp("hi");
    HasPtr2 hp2 = hp;

    cout << "hp ps: " << *(hp.get_ps()) << endl;
    cout << "hp2 ps: " << *(hp2.get_ps()) << endl;

    // 修改ph的值ph2的值不会改变
    *hp.get_ps() = "hi2";
    cout << "hp ps: " << *(hp.get_ps()) << endl;
    cout << "hp2 ps: " << *(hp2.get_ps()) << endl;
    return 0;
}