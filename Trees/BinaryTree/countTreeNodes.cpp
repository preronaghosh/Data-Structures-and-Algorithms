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

    lvl1_right->left = lvl3_left;
    lvl1_right->right = lvl3_right;

    return rootNode;
}

int countNumberOfNodes_PostOrder(Node* root) {
    if (!root) return 0;
    int nLeft, nRight;

    while (root) {
        nLeft = countNumberOfNodes_PostOrder(root->left);
        nRight = countNumberOfNodes_PostOrder(root->right);

        return nLeft + nRight + 1;
    }
    return 0;
}

int countNodes_InOrder(Node* root) {
    if (!root) return 0;
    
    return countNodes_InOrder(root->left) + 1 + countNodes_InOrder(root->right);
}

int main() {
    Node* root = create3LevelBinaryTree();

    std::cout << countNodes_InOrder(root) << std::endl;

    return 0;
}