#include <iostream>
using namespace std;

class Employee {
    public:
    Employee(const string &_name) {
        name = _name;
        number = id_cursor++;
    }

    string name;
    uint number;
    static uint id_cursor;
};

uint Employee::id_cursor = 1;

int main() {
    Employee e1("zhangsan");
    Employee e2("lisi");
    Employee e3("wangwu");
    cout << e1.number << endl;
    cout << e2.number << endl;
    cout << e3.number << endl;
    return 0;
}