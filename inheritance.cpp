#include <iostream>

class Base {
public:
    int a = 1, b=2;

    virtual void printData() {
        std::cout << "a: " << a << " b:" << b << std::endl;
    }
};

class Derived : public Base {
public:
    int c=10, d=20;

    void printData() override {
        std::cout << "c: " << c << " d: " << d << std::endl;
    }
};

int main () {
    // Base b;
    Derived d;
    d.Base::printData();
    d.Derived::printData();

    d.printData();

    Base* bPtr = new Derived();
    bPtr->printData();

    Derived d2;
    Base b2 = d2; // object slicing
    b2.printData();
}