#pragma once
#include "Base.h"

class Dog : public Animals{
    public:
    void set_name(string &name);
    string get_name();
    string name;

    void wangwang();
    private:
    int age;
};