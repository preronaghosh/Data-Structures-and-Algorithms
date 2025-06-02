#include <iostream>

void printName(int n) {
    if (n==0) return;

    std::cout << n << " Prerona" << std::endl;
    printName(n-1);
}

int main() {
    printName(5);

    return 0;
}