// #include <iostream>

class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Animal makes a sound." << std::endl;
    }

    // virtual void foo() const {  // ✅ 基类中声明
    //     std::cout << "Animal foo" << std::endl;
    // }
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Cat meows." << std::endl;
        foo();  // ✅ 可以调用 foo()
    }

    void foo() const{  // ✅ 派生类重写
        std::cout << "Cat foo" << std::endl;
    }
};

int main() {
    Animal* animal = new Cat();
    animal->makeSound();  // ✅ 输出：
                          // Cat meows.
                          // Cat foo
    delete animal;
    return 0;
}


#include <iostream>

class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Animal makes a sound." << std::endl;
    }

};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Cat meows.111" << std::endl;
        foo();
    }

    void foo() const {
        std::cout << "Cat foo" << std::endl;
    }
};

int main() {
    Cat cat;
    Animal* animalPtr = &cat;  // ✅ 通过指针避免切片
    animalPtr->makeSound();    // ✅ 调用 Cat::makeSound()
}

// 结论，继承发生切片，只是隐藏了子类的部分，但是子类的成员
// 函数仍然存在，只是不能通过基类对象调用，可以通过引用或指针调用。
