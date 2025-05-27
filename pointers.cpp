
#include <iostream>


int main() {
    int val = 10;
    void* ptr = &val;

    std::cout << "Address of val: " << &val << std::endl;
    std::cout << "Address stored in ptr after casting to int*: " << (int*)ptr << std::endl;
    std::cout << "Address stored in ptr: " << (double*)ptr << std::endl;
    std::cout << "Value at ptr: " << *((int*)ptr) << std::endl;
    std::cout << "Address of ptr: " << &ptr << std::endl;

    // Double pointer exercise
    void** ptr2 = &ptr; // pointer to another pointer
    std::cout << "Dereferencing value inside ptr2 = address of ptr: " << *ptr2 << std::endl;
    std::cout << "Printing address of ptr2: " << &ptr2 << std::endl;
    std::cout << "Printing value stored inside ptr2: " << ptr2 << std::endl;

    // Triple pointer exercise
    void*** ptr3 = &ptr2;
    std::cout << "Just printing ptr3: " << (int***)ptr3 << std::endl;
    std::cout << "Deref ptr3: " << *ptr3 << std::endl;
    std::cout << "***((int***)ptr3): " << *((int*)**ptr3) << std::endl; // deref ***ptr3 to get *ptr -> then cast to int* -> then deref again to get 10 printed 


    std::cout << **ptr3 << std::endl; // *ptr

    return 0;
}