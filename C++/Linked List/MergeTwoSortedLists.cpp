#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* list1, Node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    Node* mergedHead = nullptr;
    if (list1->data <= list2->data) {
        mergedHead = list1;
        list1 = list1->next;
    } else {
        mergedHead = list2;
        list2 = list2->next;
    }
    
    Node* mergedTail = mergedHead;
    while (list1 && list2) {
        if (list1->data <= list2->data) {
            mergedTail->next = list1;
            list1 = list1->next;
        } else {
            mergedTail->next = list2;
            list2 = list2->next;
        }
        mergedTail = mergedTail->next;
    }
    
    // Attach remaining nodes
    mergedTail->next = (list1) ? list1 : list2;

    return mergedHead;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    // Insert elements into list1
    insertAtEnd(list1, 1);
    insertAtEnd(list1, 3);
    insertAtEnd(list1, 5);

    // Insert elements into list2
    insertAtEnd(list2, 2);
    insertAtEnd(list2, 4);
    insertAtEnd(list2, 6);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    // Merge the lists
    Node* mergedList = mergeSortedLists(list1, list2);
    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
