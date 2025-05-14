#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data{val}, next{nullptr} {}
};

class List {
    Node* head;
    Node* tail;

public:
    List() : head{nullptr}, tail{nullptr} {}

    // Add node at the end of the list
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Remove node from end of list
    void pop_back() {
        if (!head) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }

    // Return data at the last node
    int back() const {
        if (tail)
            return tail->data;
        return -1;
    }

    // Check if the list is empty
    bool empty() const {
        return head == nullptr;
    }

    ~List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class Stack {
    List list;
    int capacity;
    int topIndex;

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == capacity - 1;
    }

public:
    Stack(int size) : capacity{size}, topIndex{-1} {}

    int top() const {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return list.back();
    }

    void push(int val) {
        if (isFull()) {
            std::cout << "Stack is full" << std::endl;
            return;
        }
        list.push_back(val);
        topIndex++;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        list.pop_back();
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
