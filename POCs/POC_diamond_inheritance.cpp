#include <iostream>

class A {
   public:
    std::string name;
    int HP;
    int energy;
    int attack;

    A(std::string aName) : name(aName), HP(10), energy(10), attack(0){};
    void sayHello() {
        std::cout << "hello from class A" << std::endl;
    };
    void printAttributes() {
        std::cout << "name: " << name << " HP: " << HP << " energy: " << energy << " attack: " << attack << std::endl;
    }
};

class B : virtual public A {
   public:
    B(std::string aName) : A(aName) {
        name = aName;
        HP = 100;
        energy = 50;
        attack = 20;
    };
    void sayHello() {
        std::cout << "hello from class B" << std::endl;
    };
};

class C : virtual public A {
   public:
    C(std::string aName) : A(aName) {
        name = aName;
        HP = 100;
        energy = 100;
        attack = 30;
    };
    void sayHello() {
        std::cout << "hello from class C" << std::endl;
    };
};

class D : public B, public C {
   public:
    std::string name;

    D(std::string aName) : A(aName), B(aName), C(aName) {
        name = aName;
        HP = B::HP;
        energy = C::energy;
        attack = B::attack;
    };
};

int main() {
    A a("this is A");
    a.sayHello();
    B b("this is B");
    b.sayHello();
    C c("this is C");
    c.sayHello();
    D d("this is D");

    std::cout << &b.name << std::endl;
    std::cout << &c.name << std::endl;

    a.printAttributes();
    b.printAttributes();
    c.printAttributes();
    d.printAttributes();
}
