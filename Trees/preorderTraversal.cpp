#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

void print(int val) {
    std::cout << val << " ";
}

// recursive
void preorder(TreeNode* node) {
    if (node == nullptr) return;

    // root - left - right
    print(node->val);
    preorder(node->left);
    preorder(node->right);
}

int main() {   
    TreeNode* root = new TreeNode(1);
    TreeNode* left_1 = new TreeNode(2);
    TreeNode* right_1 = new TreeNode(3);
    // create level 1
    root->left = left_1;
    root->right = right_1;

    TreeNode* left_2 = new TreeNode(4);
    TreeNode* right_2 = new TreeNode(5);
    TreeNode* left_3 = new TreeNode(6);
    TreeNode* right_3 = new TreeNode(7);
    // create level 2
    root->left->left = left_2;
    root->left->right = right_2;
    root->right->left = left_3;
    root->right->right = right_3;

    preorder(root);
    std::cout << std::endl;

    return 0;
}