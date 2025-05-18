#include <vector>
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data{val}, left{nullptr}, right{nullptr} {} 
};

void addNewNodeToBST(Node* root, int val) {
    Node* temp = root;
    Node* prev = nullptr;

    while (temp) {
        prev = temp;

        if (val == temp->data) return;  // Duplicate, ignore

        if (val < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    Node* newNode = new Node(val);
    if (val < prev->data)
        prev->left = newNode;
    else
        prev->right = newNode;
}

Node* createBstFromKeys(std::vector<int>& values) {
    Node* root = new Node(values[0]);
    for(size_t i=1; i<values.size(); i++) {
        addNewNodeToBST(root, values[i]);   
    }
    return root;
}

void printTreeInOrder(Node* root) {
    if (!root) return;
    printTreeInOrder(root->left);
    std::cout << root->data << " ";
    printTreeInOrder(root->right);
}

int main() {
    std::vector<int> values = {9, 15, 5, 20, 16, 8, 12, 3, 6};

    auto root = createBstFromKeys(values);
    printTreeInOrder(root);

    return 0;
}