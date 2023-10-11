#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
};

void reverse(Node** head_ref)
{
	Node* temp = NULL;
	Node* current = *head_ref;

	while (current != NULL) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp != NULL)
		*head_ref = temp->prev;
}

void push(Node** head_ref, int new_data)
{

	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = NULL;
    Node *temp;
    temp=*head_ref;
if(temp==NULL){
    *head_ref=new_node;
    new_node->prev=NULL;
}
else{
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->prev=temp;

}
}
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

int main()
{
	Node* head = NULL;
char c='y';
	
    while(c=='y'){
        cout<<"Enter the element in doubly linked list ";
        int x;
        cin>>x;
        push(&head,x);
        cout<<"Do you want to add more elements(y/n) ";
        cin>>c;
    }

	cout << "Linked list" << endl;
	printList(head);
	reverse(&head);
	cout << "\nReversed Linked list" << endl;
	printList(head);

	return 0;
}

