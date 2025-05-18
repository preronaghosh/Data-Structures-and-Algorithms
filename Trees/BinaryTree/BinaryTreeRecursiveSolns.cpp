#include <iostream>

struct Node {
    Node* left;
    int data;
    Node* right;

    Node(int val) : left{nullptr}, right{nullptr}, data{val} {}
};

Node* create3LevelBinaryTree() {
    Node* rootNode = new Node(1);
    Node* lvl1_left = new Node(2);
    Node* lvl1_right = new Node(3);

    Node* lvl2_left = new Node(4);
    Node* lvl2_right = new Node(5);

    Node* lvl3_left = new Node(6);
    Node* lvl3_right = new Node(7);
    Node* lvl4_left = new Node(8);
    Node* lvl4_right = new Node(9);

    // attach all nodes
    rootNode->left = lvl1_left;
    rootNode->right = lvl1_right;

    lvl1_left->left = lvl2_left;
    lvl1_left->right = lvl2_right;

    lvl1_right->left = lvl3_left;
    lvl1_right->right = lvl3_right;

    return rootNode;
}

// Function to print pre order traversal of the current tree
// Root -> left -> right
// Use stack for iterative versions
void printPreOrderTraversal(Node* root) {
    if (!root) return;
    std::cout << root->data << " ";
    printPreOrderTraversal(root->left);
    printPreOrderTraversal(root->right);
}

// Function to print post order traversal of the current tree
// Left -> Right -> Root
void postOrderTraversal(Node* root) {
    if (!root) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data << " ";
}

// Function to print in order traversal of the current tree
// Left -> Root -> Right
void inOrderTraversal(Node* root) {
    if (!root) return;
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {

    Node* root = create3LevelBinaryTree();  
    std::cout << "Pre order: ";
    printPreOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Post order: ";
    postOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "In order: ";
    inOrderTraversal(root);
    std::cout << std::endl;
}

