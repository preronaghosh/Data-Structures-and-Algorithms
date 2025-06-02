#include <iostream>

void count(int num, int& result) {
    if (num == 0) return;
    if (num > 0) result++;
    count(num/10, result);
}

int main() {
    int result = 0;
    count(1235675478, result);
    std::cout << result << std::endl;
}