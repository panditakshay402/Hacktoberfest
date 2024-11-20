#ifndef TREE_H_
#define TREE_H_

class Tree {
    private:
        //define extra members or methods if required
    public:
        // data members:
        int data_;
        Tree* left_;
        Tree* right_;

        // constructor:
        Tree(int value, Tree* left = nullptr, Tree* right = nullptr) {
            this->data_ = value;
            this->left_ = left;
            this->right_ = right;
        }
};

#endif