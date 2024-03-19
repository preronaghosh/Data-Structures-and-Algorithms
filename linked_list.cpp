// Singly linked list implementation
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value);
};

Node::Node(int value) {
    data = value;
    next = nullptr;
}

class LinkedList {
public:
    Node* head;

    LinkedList();
    ~LinkedList();
    void addNode_End(int value); // insert at the end of the list
    void addNode_Middle(int value, Node* prev_node); // insert after a given node 
    void addNode_Front(int value); // insert at the beginning of the list
    void deleteNode(int value); // delete the node with the passed value
    void displayList();
    int getListLength(); // returns the number of elements in the list
};

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    // delete the whole list
    Node* curr = head;
    Node* next;

    while(curr != nullptr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

void LinkedList::addNode_End(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    } 

    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newNode;
}

void LinkedList::addNode_Front(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void LinkedList::displayList() {
    Node* curr = head;

    while (curr != nullptr) {
        std::cout << "Node data: " << curr->data << std::endl;
        curr = curr->next;
    }
}

void LinkedList::addNode_Middle(int value, Node* prev_node) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    if (prev_node == NULL) {
        std::cout << "The given node cannot be NULL" << std::endl;
        return;
    }

    newNode->next = prev_node->next;
    prev_node->next = newNode;
}

void LinkedList::deleteNode(int value) {
    if (head == nullptr) {
        std::cout << "Empty list" << std::endl;
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = head; 
    Node* curr = head;

    while (curr != nullptr) {
        if (curr->data == value) {
            // this node has to be deleted
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    std::cout << "Node with value " << value << " not found in the list" << std::endl;
}

int LinkedList::getListLength() {
    // no elements in list
    if (head == nullptr) {
        return 0;
    }
    // single element
    if (head->next == nullptr) {
        return 1;
    }

    int count = 1;
    Node* curr = head;
    while (curr->next != nullptr) {
        count++;
        curr = curr->next;
    }
    return count;
}

int main() {
    LinkedList myList;

    // inserting nodes at the end of the list
    myList.addNode_End(1);
    myList.addNode_End(2);
    myList.addNode_End(3);
    myList.addNode_End(4);

    // inserting nodes at the beginning of the list
    myList.addNode_Front(5);
    myList.addNode_Front(6);
    myList.addNode_Front(7);
    myList.addNode_Front(8);

    myList.deleteNode(8);

    std::cout << "Linked List: " << std::endl;
    myList.displayList();

    std::cout << "The list now has " << myList.getListLength() << " elements" << std::endl;

    return 0;
}