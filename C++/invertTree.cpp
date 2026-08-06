#include <iostream>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to invert the binary tree
TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;

    // Recursively invert the left and right subtrees
    TreeNode* leftSubtree = invertTree(root->left);
    TreeNode* rightSubtree = invertTree(root->right);

    // Swap the left and right subtrees
    root->left = rightSubtree;
    root->right = leftSubtree;

    return root;
}

// Helper function to print inorder traversal of the tree
void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Inorder traversal before inversion: ";
    inorderTraversal(root);
    cout << endl;

    // Inverting the binary tree
    root = invertTree(root);

    cout << "Inorder traversal after inversion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
