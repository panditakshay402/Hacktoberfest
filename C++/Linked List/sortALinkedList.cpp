
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *merge(Node *left, Node *right)
{
    Node *dummy = new Node();
    Node *tail = dummy;

    while (left && right)
    {
        if (left->data < right->data)
        {
            tail->next = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    if (left)
    {
        tail->next = left;
    }
    else
    {
        tail->next = right;
    }

    return dummy->next;
}

Node *mergeSort(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *right = mergeSort(slow->next);
    slow->next = nullptr;
    Node *left = mergeSort(head);

    return merge(left, right);
}

int main()
{
    Node *head = new Node{1};
    head->next = new Node{3};
    head->next->next = new Node{2};
    Node *temp = head; 
    cout << "Before sorting!" << endl;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
    head = mergeSort(head);
    cout << "After sorting!" << endl;
    while (head)
    {
        std::cout << head->data << " ";
        head = head->next;
    }

    std::cout << std::endl;

    return 0;
}