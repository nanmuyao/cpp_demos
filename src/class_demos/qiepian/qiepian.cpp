// #include <iostream>

// class Animal {
// public:
//     virtual void makeSound() const {
//         std::cout << "Animal makes a sound." << std::endl;
//     }

//     // virtual void foo() const {  // ✅ 基类中声明
//     //     std::cout << "Animal foo" << std::endl;
//     // }
// };

// class Cat : public Animal {
// public:
//     void makeSound() const override {
//         std::cout << "Cat meows." << std::endl;
//         foo();  // ✅ 可以调用 foo()
//     }

//     void foo() const{  // ✅ 派生类重写
//         std::cout << "Cat foo" << std::endl;
//     }
// };

// int main() {
//     Animal* animal = new Cat();
//     animal->makeSound();  // ✅ 输出：
//                           // Cat meows.
//                           // Cat foo
//     delete animal;
//     return 0;
// }


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
        std::cout << "Cat meows." << std::endl;
    }

    void foo() const {
        std::cout << "Cat foo" << std::endl;
    }
};

int main() {
    Cat cat;
    // Animal animal = cat;  // ⚠️ 发生继承切片，Cat 的部分被“切掉”了··

    // animal.makeSound();  // ❌ 仍然调用 Animal::makeSound()
    // // animal.foo();      // ❌ 编译错误：Animal 中没有 foo()


    Animal& animal = cat;  // ✅ 通过引用避免切片
    animal.makeSound();     // ✅ 调用 Cat::makeSound()
    // animal.foo();           // ✅ 调用 Cat::foo()

    Animal* animalPtr = &cat;  // ✅ 通过指针避免切片
    animalPtr->makeSound();    // ✅ 调用 Cat::makeSound()
    // animalPtr->foo();          // ✅ 调用 Cat::foo()
}

// 结论，继承发生切片，只是隐藏了子类的部分，但是子类的成员
// 函数仍然存在，只是不能通过基类对象调用，可以通过引用或指针调用。
