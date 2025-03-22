#include <iostream>
#include "Dog.h"

void Dog::set_name(string &name)
{
    this->name = name;
}

string Dog::get_name()
{
    return this->name;
}

void Dog::wangwang()
{
    std::cout << "dog wang wang" << std::endl;
}
