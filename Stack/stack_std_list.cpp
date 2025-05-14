#include <iostream>
#include <list>

class Stack {
    std::list<int> stackList;
    int capacity;
    int topIndex;

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == capacity - 1;
    }

public:
    Stack(int size) : capacity{size}, topIndex{-1} {}

    int top() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return stackList.back();
    }

    void push(int val) {
        if (isFull()) { 
            std::cout << "Stack is full" << std::endl;
            return;
        }
        stackList.push_back(val);
        topIndex++;
    }

    void pop() {
        if (isEmpty()) { 
            std::cout << "Stack is empty" << std::endl;
            return;
        } 
        stackList.pop_back();
        topIndex--;
    }
};

int main() {
    Stack s(3);
    s.push(10);
    s.push(20);
    std::cout << "Top: " << s.top() << std::endl;  // 20
    s.push(30);
    s.push(40); // Should print "Stack is full"

    s.pop();
    std::cout << "Top: " << s.top() << std::endl;  // 20
    s.pop();
    s.pop();
    s.pop(); // Should print "Stack is empty"
    return 0;
}
