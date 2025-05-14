#include <iostream>

class Queue {
    int* arr;
    int capacity;
    int front; // points to next element that can be popped
    int rear; // points to next empty space
    int count; // number of elements in queue

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

public:

    Queue(int size) : capacity{size}, front{0}, rear{0}, count{0} {
        arr = new int[capacity];
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int val) {
        if (isFull()) { 
            std::cout << "Queue is full" << std::endl;
            return;
        }
        arr[rear] = val;
        rear = (rear+1) % capacity;
        count++;
    }

    void dequeue() {
        if (isEmpty()) { 
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        front = (front+1) % capacity;
        count--;
    }

    int peek() {
        if (isEmpty()) { 
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        return arr[front];
    }

    int size() {
        return count;
    }
};

int main() {

    Queue queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.enqueue(6); // Should print queue is full

    queue.dequeue(); // remove 1
    queue.dequeue(); // remove 2
    queue.dequeue(); // remove 3

    std::cout << queue.peek() << std::endl; // should print 4

    queue.enqueue(6);  // will work
    queue.dequeue(); // remove 4

    std::cout << queue.peek() << std::endl; // should print 5

    return 0;

}