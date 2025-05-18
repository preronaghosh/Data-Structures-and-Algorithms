#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data{val}, left{nullptr}, right{nullptr} {}
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

    lvl2_right->left = lvl3_left;
    lvl2_right->right = lvl3_right;

    lvl3_right->left = lvl4_left;
    lvl3_right->right = lvl4_right;

    return rootNode;
}

int depthOfTree(Node* root) {
    if (!root) return 0;
    int numLeft, numRight;

    numLeft = depthOfTree(root->left);
    numRight = depthOfTree(root->right);

    return std::max(numLeft, numRight) + 1;
}

int main() {
    Node* root = create3LevelBinaryTree();
    std::cout << depthOfTree(root) << std::endl;
    return 0;
}