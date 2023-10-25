/*The boundary nodes of a binary tree include the nodes from the left and right boundaries and the leaf nodes, each node considered once.*/

#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
template <typename T>
struct TreeNode {
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T x) : data(x), left(nullptr), right(nullptr) {}
};

template <typename T>
bool isLeaf(TreeNode<T> *root) {
    return !root->left && !root->right;
}

template <typename T>
void addLeftBoundary(TreeNode<T> *root, vector<T> &res) {
    TreeNode<T> *cur = root->left;
    while (cur) {
        if (!isLeaf(cur))
            res.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

template <typename T>
void addLeaves(TreeNode<T> *root, vector<T> &res) {
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaves(root->left, res);
    if (root->right)
        addLeaves(root->right, res);
}

template <typename T>
void addRightBoundary(TreeNode<T> *root, vector<T> &res) {
    TreeNode<T> *cur = root->right;
    vector<T> tmp;
    while (cur) {
        if (!isLeaf(cur))
            tmp.push_back(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    for (int i = tmp.size() - 1; i >= 0; i--)
        res.push_back(tmp[i]);
}

template <typename T>
vector<T> traverseBoundary(TreeNode<T> *root) {
    vector<T> res;
    if (!root)
        return res;
    if (!isLeaf(root))
        res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}

int main() {
    // Create your binary tree here
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    vector<int> result = traverseBoundary(root);

    // Print the boundary nodes
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
