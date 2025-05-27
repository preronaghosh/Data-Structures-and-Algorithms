#include <iostream>

int main() {
    int arrData[10] = {1,2,3,4,5,6,7,8,9,10}; // array of integer type data
    int* arr[10]; // array of pointers to int type of data
    for(int i=0; i<10; i++) {
        arr[i] = &arrData[i];
    }

    for(int i=0; i<10; i++) {
        std::cout << arr[i] << std::endl;
    }

    // --------------------------------------------
    int* arr2 = new int[5]; // arr2 is a single pointer to first address of heap allocated 5x4 bytes of int memory
    for(int i=0; i<5; i++) {
        arr2[i] = i;
    }
    for(int i=0; i<5; i++) {
        std::cout << arr2[i] << std::endl;
    }

    delete[] arr2;

    return 0;
}