#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val) : val{val}, next{nullptr} {}
}; 

void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

Node* getMiddle(Node* head) {
    if (!head) return nullptr;

    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result = nullptr;

    if (left->val <= right->val) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) {
        return head;
    }

    Node* middle = getMiddle(head);
    Node* right = middle->next;
    middle->next = nullptr;

    Node* left = mergeSort(head);
    right = mergeSort(right);

    return merge(left, right);
}

int main () {
    Node* head = new Node(5);
    Node* curr = head;
    int values[] = {4, 3, 2, 1, 10, 9, 8, 7, 6};
    for (auto val : values) {
        Node* newNode = new Node(val);
        curr->next = newNode;
        curr = curr->next;
    }

    std::cout << "List before sorting: " << std::endl;
    printList(head);

    head = mergeSort(head);

    std::cout << "List after sorting: " << std::endl;
    printList(head);

    // Clean up memory
    curr = head;
    Node* next;
    while (curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }

    return 0;
}
