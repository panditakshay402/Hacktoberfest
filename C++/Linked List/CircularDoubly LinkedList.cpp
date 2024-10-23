#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

// Class to represent a circular doubly linked list
class CircularDoublyLinkedList {
public:
    Node* head;
    CircularDoublyLinkedList() : head(NULL) {}

    // Function to insert a node at the end of the list
    void insert(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    // Function to display the list from the head
    void display() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularDoublyLinkedList cdll;
    cdll.insert(1);
    cdll.insert(2);
    cdll.insert(3);
    cdll.insert(4);

    // Display the circular doubly linked list
    cdll.display();

    return 0;
}
