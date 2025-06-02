#include <iostream>

void printNumbers(int n) {
    if (n==0) return;

    printNumbers(n-1);
    std::cout << n << std::endl;
}

int printNumberWithBacktrack(int n) {
    if (n==0) return 1;

    int x = printNumberWithBacktrack(n-1);
    std::cout << x << " ";
    return x+1;
}

int main() {
    printNumbers(10);

    std::cout << "Second one:" << std::endl;
    printNumberWithBacktrack(20);
    std::cout << std::endl;
    return 0;
}