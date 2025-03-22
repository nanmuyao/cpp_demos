#include "Dog.h"
#include "Base.h"
#include <iostream>

Dog getDog1() {
    Dog d = Dog();
    d.name = "xiaode";
    return d;
}

Animals getDog2() {
    Animals d = Dog();
    return d;
}

int main() {
    Animals d = getDog2();
    std::cout << d.name << endl;
    return 0;
}