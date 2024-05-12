#include <iostream>

struct Node {
    int val;
    Node* next;
    Node* prev;

    // constructor
    Node(int val) {
        val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void append(int data); // Function to add a node at the end of the list
    void displayForward();  // Function to display the list forward
    void displayBackward();  // Function to display the list backward
    void prepend(int data); // Adds a node at the beginning of the list
    void insertAfter(Node* prevNode, int data) // Inserts a new node after a given node

};

void DoublyLinkedList::insertAfter(Node* prevNode, int data) {
    if (prevNode == nullptr) return;
    Node* newNode = new Node(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;

    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    } else { // we are appending at the end
        tail = newNode;
    }
}

void DoublyLinkedList::append(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DoublyLinkedList::prepend(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) head = tail = newNode;
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoublyLinkedList::displayForward() {
    if (head == nullptr) return;

    Node* curr = head;
    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::displayBackward() {
    Node* current = tail;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

int main() {
    return 0;
}