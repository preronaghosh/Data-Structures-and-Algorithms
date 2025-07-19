/* Swap 2 numbers using Bit manipulation */

#include <iostream>
using namespace std;

int main() {
    int a=10, b=20;

    // swap two numbers using XOR operation
    a = a ^ b;  
    b = a ^ b; // a here is a^b, so eq => b = (a^b) ^ b  = a ^ 0 = a. So, b=a here
    a = a ^ b; // eq => a = a^b and b = a. So, eq => a = (a ^ b) ^ a = b (Substitute both values here)

    cout << "a : " << a << " b: " << b << endl;
}