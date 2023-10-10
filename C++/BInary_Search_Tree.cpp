#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
class Node
{
public:
    int data;
    Node *parent;
    Node *left;
    Node *right;

    Node(int val, Node *p, Node *l, Node *r)
    {
        data = val;
        parent = p;
        left = l;
        right = r;
    }
};
/*
the general structure of one node will be
    Parent Node
         ||
         ||
         Node        //this Curent also would be the left or right child node of the parent  node
       //   \\
      //     \\      //one edge for the left child or right child link and the other edges from that child nodes to its parent are parent link
     //       \\
    Left     Right
    child    child
    Node     Node
*/
class Binary_search_tree
{
private:
    Node *root;
    /*
    the structure of one node will be
             NULL
              |
              |
             Node        //<--Root Node
           //    \\
          //      \\
         //        \\
        Left      Right
        child     child
        Node      Node
    */
    void bstree_insert_node(Node *temp, int val) // the recursive function to insert data in the Binary Search Tree
    {
        if (val < temp->data) // if the current element's value is less than the current node's value we are visiting then...
        {
            if (temp->left == NULL) // if the left of the current node have nothing...
            {
                temp->left = new Node(val, temp, NULL, NULL); // we can add a new node and assign the value to that node
            }
            else // if the left of the current node have any node, then...
            {
                bstree_insert_node(temp->left, val); // we would call this function recursively passing the left node of the current node and the value as parameters
            }                                        // which basically means that the value is less than the value of the current node, so it will be positioned to left-subtree of the current node
        }
        else // the current element's value is greater than the current node's value we are visiting then...
        {
            if (temp->right == NULL) // if the right of the current node have nothing...
            {
                temp->right = new Node(val, temp, NULL, NULL); // we can add a new node and assign the value to that node
            }
            else // if the right of the current node have any node, then...
            {
                bstree_insert_node(temp->right, val); // we would call this function recursively passing the right node of the current node and the value as parameters
            }                                         // which basically means that the value is less than the value of the current node, so it will be positioned to right-subtree of the current node
        }
    }
    Node *bstree_find_node(Node *temp, int val)
    {
        while (temp != NULL)      // iterating through the valid nodes
        {                         // here we will use the binary search approach...
            if (val < temp->data) // if the value we want to find is less than the value of the current node's value...then
            {
                temp = temp->left; // then we would only go to the left of the current node as the right subtree of the node will have values larger than the current node's value
            }
            else if (val > temp->data) // if the value we want to find is greater than the value of the current node's value...then
            {
                temp = temp->right; // then we would only go to the right of the current node as the left subtree of the node will have values less than the current node's value
            }
            else // the condition when we find the value in the current node...
                 // because of the trichotomy of two integers...which states that two intergers can only have one of three possible relations
            { // which are a<b or a=b or a>b when a and b both are integres
                break;
            }
        }
        return temp;
    }
    Node *bstree_find_min(Node *temp)
    {
        while (temp->left != NULL)//the smallest element node will be at the left most position
        {           //this is because when we compare that value while inserting it, it will come to the left subtree of the root node and the it will again come to the left subtree of the current node...and so on...
            temp = temp->left;//that is why we are going to the left most node possible and returning that node
        }
        return temp;
    }
    void bstree_delete_node(Node *temp)
    {
        if (temp->left == NULL && temp->right == NULL)//if the node we want to delete is a leaf node
        {
            if (temp == root)//if the tree has only one node, the root node, then we have to check that possibility...
            {
                delete temp;
                root = NULL;//and then root will be again initialized as NULL, which means the tree is empty
            }
            else if (temp == temp->parent->left)//if the node is a leaf node but left child of it's parent
            {
                temp->parent->left = NULL;//the parent's left pointer should be set to NULL
                delete temp;
            }
            else
            {
                temp->parent->right = NULL;//else it will be right child of it's parent
                delete temp;
            }
        }
        else if (temp->left != NULL && temp->right == NULL)//if the node has left child but has no right child
        {
            if (temp == root)   //if the node is root...
            {
                root = temp->left;//so the new root will be the left child of the current root...
                root->parent = NULL;//the parent of the root node is set to NULL
                delete temp;
            }
            else if (temp == temp->parent->left)//if it is the left child of it's parent
            {
                temp->parent->left = temp->left;//parent's left pointer in set to the left child of the current node
                temp->left->parent = temp->parent;//the parent link of the left child of the current node is managed and set to the parent of the current node
                delete temp;
            }
            else//else it will be the right child of it's parent
            {
                temp->parent->right = temp->left;//parent's right pointer in set to the left child of the current node
                temp->left->parent = temp->parent;//the parent link of the left child of the current node is managed and set to the parent of the current node
                delete temp;
            }
        }
        else if (temp->left == NULL && temp->right != NULL)//if the node has no left child but has right child
        {
            if (temp == root) //if the node is root...
            {
                root = temp->right;//so the new root will be the right child of the current root...
                root->parent = NULL;//the parent of the root node is set to NULL
                delete temp;
            }
            else if (temp == temp->parent->left)//if it is the left child of it's parent
            {
                temp->parent->left = temp->right;//parent's left pointer in set to the right child of the current node
                temp->right->parent = temp->parent;//the parent link of the left child of the current node is managed and set to the parent of the current node
                delete temp;
            }
            else
            {
                temp->parent->right = temp->right;//parent's right pointer in set to the right child of the current node
                temp->right->parent = temp->parent;//the parent link of the left child of the current node is managed and set to the parent of the current node
                delete temp;
            }
        }
        else//the case when the node has both childs...or both left and right subtrees...
        {
            Node *temp_min = bstree_find_min(temp->right);//then we will replace the current node's value with it's successor's value and then eventually delete the successor node...
            temp->data = temp_min->data;//the data is copied
            bstree_delete_node(temp_min);//now we are recursively calling this function and deleting the successor node...
            //if we closely study the code for deleting a node in  binary search tree, we would notice that when we want to delete one node, either one leaf node or parent of a leaf nod will be eventually deleted...
        }
    }
    void bstree_show_data(Node *temp)
    {
        if (temp != NULL)
        {
            bstree_show_data(temp->left);
            cout << setw(5) << temp->data << endl;
            bstree_show_data(temp->right);
        }
    }
    void bstree_inorder_traversal(Node *temp)
    {
        if (temp != NULL)//inorder traversal of the tree using recursive function
        {
            bstree_inorder_traversal(temp->left);//first we traverse the left subtree of the curent node as the values in the left subtree of this current node will be less than the curent node's data
            cout << temp->data << " ";          //then we will print the current node's data
            bstree_inorder_traversal(temp->right);//then we traverse the right subtree of the curent node as the values in the right subtree of this current node will be greater than the curent node's data
        }
    }
    void bstree_inorder_morris_traversal(Node *temp)//the iterative function for inorder traversal
    {
        Node *curr = root;//the cuurent node is initialized at root
        Node *pre = NULL;
        while (curr != NULL)
        {
            if (curr->left == NULL)//the condition when the left subtree of the current node is traversed
            {
                cout << curr->data << " ";//then we print the current node's data
                curr = curr->right;//then we move the current pointer to the right of the current node
            }
            else
            {
                pre = curr->left;//initially the left subtree of the current node will be traversed...
                while (pre->right != NULL && pre->right != curr)
                {
                    pre = pre->right;//so we are going to the node which right most
                }
                if (pre->right == NULL) //now we connect the right most node's right pointer to the current node, cause it will forward us while we traverse the left subtree and then complete it...
                {
                    pre->right = curr;//the tree structure is manipulated here...we will correct it later...
                    curr = curr->left;//now we come to the left child of the current node...
                }
                else
                {
                    pre->right = NULL; //this is the case when we have completed traversing the left subtree...
                    cout << curr->data << " ";//now we print the value of the current node
                    curr = curr->right;//now we go to the right child of the current node
                }
            }
        }
    }
    void bstree_preorder_traversal(Node *temp)
    {
        if (temp != NULL)
        {
            cout << temp->data << " ";//first we print the current node's data
            bstree_preorder_traversal(temp->left);//then we traverse the left subtree of the curent node as the values in the left subtree of this current node will be less than the curent node's data
            bstree_preorder_traversal(temp->right);//then we traverse the right subtree of the curent node as the values in the right subtree of this current node will be greater than the curent node's data
        }
    }
    void bstree_preorder_morris_traversal(Node *temp)
    {
        Node *curr = root;      //in this case also we are manipulating the structure as we did in inorder traversal, the only change the order we print the data of the current node, the left subtree and right subtree
        Node *pre = NULL;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                cout << curr->data << " ";
                curr = curr->right;
            }
            else
            {
                pre = curr->left;
                while (pre->right != NULL && pre->right != curr)
                {
                    pre = pre->right;
                }
                if (pre->right == NULL)
                {
                    cout << curr->data << " ";
                    pre->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pre->right = NULL;
                    curr = curr->right;
                }
            }
        }
    }
    void bstree_postorder_traversal(Node *temp)
    {
        if (temp != NULL)
        {
            bstree_postorder_traversal(temp->left);//first we traverse the left subtree of the curent node as the values in the left subtree of this current node will be less than the curent node's data
            bstree_postorder_traversal(temp->right);//then we traverse the right subtree of the curent node as the values in the right subtree of this current node will be greater than the curent node's data
            cout << temp->data << " ";//then we print the current node's data
        }
    }
    void bstree_postorder_morris_traversal(Node *temp)
    {//in this case also we are manipulating the structure as we did in inorder traversal, the only change the order we print the data of the current node, the left subtree and right subtree
        vector<Node *> vec;//we are using a vector to store the data...
        Node *curr = root;
        Node *pre = NULL;
        while (curr != NULL)
        {
            if (curr->right == NULL)
            {
                vec.push_back(curr);//in the vector we are storing the data in the manner that first the root then left child then right child...
                curr = curr->left;
            }
            else
            {
                pre = curr->right;
                while (pre->left != NULL && pre->left != curr)
                {
                    pre = pre->left;
                }
                if (pre->left == NULL)
                {
                    vec.push_back(curr);
                    pre->left = curr;
                    curr = curr->right;
                }
                else
                {
                    pre->left = NULL;
                    curr = curr->left;
                }
            }
        }
        reverse(vec.begin(), vec.end());//...but we want totally the opposite... so we have reversed the vector...
        for (auto i : vec)
        {
            cout << i->data << " ";
        }
    }

public:
    Binary_search_tree()
    {
        root = NULL;
    }
    void insert_node(int val)
    {
        if (root == NULL) // if the root node is NULL,that means that the tree is empty...
        {
            root = new Node(val, NULL, NULL, NULL); // we create a new Node and assign it as root
        }
        else
        {
            bstree_insert_node(root, val); // if the root exists that means the tree is not empty...then we call this function to insert the value
        }
    }
    void show_data()
    {
        cout << "In-order walk" << endl;
        bstree_show_data(root);
    }
    void search_node(int val)
    {
        Node *temp = bstree_find_node(root, val);
        if (temp != NULL)
        {
            cout << "Data found " << endl;
        }
        else
        {
            cout << "No such data found" << endl;
        }
    }
    void delete_node(int val)
    {
        if (root == NULL) // if the tree is empty...
        {
            cout << "No data is present in the tree" << endl;
        }
        else
        {
            Node *temp = bstree_find_node(root, val); // else we find the node with the given value
            if (temp != NULL)                         // if such data is present then that would be deleted...
            {
                cout << temp->data << " is deleted" << endl;
                bstree_delete_node(temp); // by calling this function
            }
            else
            {
                cout << "No such data is present" << endl; // if no such data exists then it will show this message
            }
        }
    }
    void show_root_data()
    {
        cout << "Root data" << endl;
        cout << setw(5) << root->data << endl;
    }
    void inorder_traversal()
    {
        cout << "In-order traversal using recursion" << endl;
        bstree_inorder_traversal(root);
    }
    void inorder_morris_traversal()
    {
        cout << "Inorder traversal using Morris Traversal" << endl;
        bstree_inorder_morris_traversal(root);
    }
    void preorder_traversal()
    {
        cout << "Pre-order traversal using recursion" << endl;
        bstree_preorder_traversal(root);
    }
    void preorder_morris_traversal()
    {
        cout << "Pre-order traversal using Morris traversal" << endl;
        bstree_preorder_morris_traversal(root);
    }
    void postorder_traversal()
    {
        cout << "Post-order traversal using recursion" << endl;
        bstree_postorder_traversal(root);
    }
    void postorder_morris_traversal()
    {
        cout << "Post-order traversal using Morris traversal" << endl;
        bstree_postorder_morris_traversal(root);
    }
};
int main()
{
    Binary_search_tree obj;

    obj.insert_node(10);
    obj.insert_node(5);
    obj.insert_node(4);
    obj.insert_node(9);
    obj.insert_node(18);
    obj.insert_node(17);
    obj.insert_node(2);
    obj.insert_node(1);
    obj.insert_node(3);
    obj.insert_node(16);
    obj.insert_node(13);
    obj.insert_node(11);
    obj.insert_node(12);
    obj.insert_node(14);

    obj.show_data();
    obj.show_root_data();
    obj.search_node(45);
    obj.delete_node(10);

    obj.show_data();
    obj.show_root_data();

    obj.inorder_traversal();
    cout << endl;
    obj.inorder_morris_traversal();
    cout << endl;

    obj.preorder_traversal();
    cout << endl;
    obj.preorder_morris_traversal();
    cout << endl;

    obj.postorder_traversal();
    cout << endl;
    obj.postorder_morris_traversal();
    cout << endl;

    return 0;
}