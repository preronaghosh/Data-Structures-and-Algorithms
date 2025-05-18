#include <iostream>
using namespace std;

// Define a node of the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert a value into the BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

// Inorder traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

bool searchBst(Node* root, int target) {
    if (!root) return false;

    Node* temp = root;
    while (temp) {
        if (target == temp->data) return true;
        else if (target < temp->data) {
            // left subtree
            temp = temp->left;
        } else {
            // go to right st
            temp = temp->right;
        }
    }
    return false;
}

bool recursiveSearchBst(Node* root, int target) {
    if (!root) return false;

    if (root->data == target) {
        return true;
    } else if (root->data > target) {
        recursiveSearchBst(root->left, target);
    } else {
        recursiveSearchBst(root->right, target);
    }
}

// Iterative method
void addNewNodeToBST(Node* root, int val) {
    if (!root) return;
    Node* temp = root;
    Node* prev = nullptr;
    while (temp) {
        if (temp->data == val) return;
        
        prev = temp;
        if (temp->data < val) temp = temp->right;
        else temp = temp->left;
    }
    
    Node* newNode = new Node(val);
    if (val < prev->data) {
        prev->left = newNode;
    } else {
        prev->right = newNode;
    }
}

/*
        50
       /  \
     30    70
    /  \   / \
  20   40 60 80

*/

int main() {
    Node* root = nullptr;

    // Insert nodes
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal of the BST: ";
    inorderTraversal(root);
    std::cout << std::endl;

    int targetVal = 55;
    std::cout << "Searching val: " << targetVal << " in BST.." << std::endl;
    searchBst(root, targetVal) ? std::cout << "Found!" << std::endl : std::cout << "Not Found!" << std::endl;


    recursiveSearchBst(root, 12) ? std::cout << "RSearch: Found" : std::cout << "Rsearch: Not found";
    std::cout << std::endl;

    addNewNodeToBST(root, 34);
    inorderTraversal(root);
    return 0;
}
