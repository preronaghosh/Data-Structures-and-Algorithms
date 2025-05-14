#include <iostream>

class Stack {
    int* arr;
    int capacity;
    int topIndex;
public:
    Stack(int size) : capacity{size}, topIndex{-1} {
        arr = new int[capacity];
    }

    int top() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return arr[topIndex];
    }

    void push(int val) {
        if (isFull()) {
            std::cout << "Stack is full" << std::endl;
            return;
        }
        arr[++topIndex] = val;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        topIndex--;
    }

    ~Stack() {
        delete[] arr;
    }

private:
    bool isEmpty() {
        return topIndex == -1;
    }
    bool isFull() { return topIndex == (capacity - 1); }
};

int main() {
    Stack s(10);

    s.push(5);
    s.push(6);
    s.push(7);
    std::cout << s.top() << std::endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}