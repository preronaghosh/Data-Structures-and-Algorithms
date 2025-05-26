/* Implement my own std::vector (dynamic array) */

#include <iostream>
using namespace std;

class Vector {
    int* arr;
    int capacity;
    int count;

    bool isFull() {
        return count == capacity;
    }

    void resize() {
        cout << "Resizing.." << endl;
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];
        // copy existing data from arr[] to newArr[]
        for (int i=0; i<count; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    Vector(int size) : capacity{size}, count{0} {
        arr = new int[capacity];
    }

    void push_back(int val) {
        if (isFull()) {
            // resize
            resize();

        }
        arr[count++] = val;
    }

    int size() { return count; }

    int getCapacity() { return capacity; }

    void pop_back() {
        if (empty()) {
            return;
        }
        count--;
    }

    bool empty() {
        return count == 0;
    }

    ~Vector() {
        delete[] arr;
    }

    // [] operator overloading
    int& operator[](int index) {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }
};


int main() {
    Vector v(3);
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.pop_back();

    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
}