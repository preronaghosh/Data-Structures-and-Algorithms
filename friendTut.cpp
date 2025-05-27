#include <iostream>

class FriendClass {
    int a{30}, b{40};

    friend void displayAB(FriendClass*);
    friend class UserClass;
};

void displayAB(FriendClass* o) {
    std::cout << o->a << " " << o->b << std::endl;
}

class UserClass {
public:
    FriendClass fc;

    void printFCData() {
        std::cout << "a " << fc.a << std::endl;
        std::cout << "b: " << fc.b << std::endl;
    }
};

int main() {

    FriendClass obj;
    displayAB(&obj);

    std::cout << "Print FriendClass data using UserClass object\n";
    UserClass uc;
    uc.printFCData();

}
