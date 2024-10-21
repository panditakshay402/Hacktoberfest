#include <iostream>
#include "tree.h"

using namespace std;

class Traversals {
    public:
        void PreorderTraversal(Tree* root) {
            if (root == nullptr) return; 

            cout << root->data_ << " -> ";  
            PreorderTraversal(root->left_);
            PreorderTraversal(root->right_); 
        }

        void InorderTraversal(Tree* root) {
            if (root == nullptr) return; 

            InorderTraversal(root->left_);
            cout << root->data_ << " -> ";  
            InorderTraversal(root->right_); 
        }

        void PostorderTraversal(Tree* root) {
            if (root == nullptr) return; 

            PostorderTraversal(root->left_);
            PostorderTraversal(root->right_); 
            cout << root->data_ << " -> ";    
        }
};
