// Question: Remove duplicates from an sorted doubly linked list (DLL)
#include<iostream>
using namespace std;

class node{  //defining structure of DLL
public:
    node * prev; //condition for DLL
    node *  next;
    int data;

    node(int data){  //constructor

        this->data=data;
        prev=nullptr;
        next=nullptr;
    }

}; 

class DoublyLL{
public:
    node * head;

    DoublyLL(){   //constructor
        head=nullptr;
    }

};

void displayLL(node * head){
    if(head == nullptr) {    //if a list is empty
        cout << "NULL";
        return;
    }

    node * temp = head;    //saving head node in temp node

    while(temp)
    {

        cout << temp->data << "<->";
        temp = temp->next; 
    }

    cout << "NULL";
}

void removeDuplicates(node* &head)
{
    if(head==NULL)
    {
        cout<<"Empty Doubly Linked List!!";
        return;
    }
    
    if(head -> next == NULL) 
    {
        cout << "Single Node in doubly Linked List" << endl;
        return ;
    }
    
    node* curr = head;
    
    while(curr!=NULL)
    {
        if(curr->next!=NULL && (curr->data == curr->next->data))
        {
            node* temp = curr->next;
            curr->next = temp->next;
            temp->next = NULL;    //to avoid memory leak
            delete temp;
            
        }
        
        else
        {
             curr = curr->next; 
        }
    }
}

int main(){

    DoublyLL dll; //initializing 
    dll.head = new node(1);
    dll.head->next = new node(1);
    dll.head->next->prev = dll.head;
    dll.head->next->next = new node(2);
    dll.head->next->next->prev = dll.head->next;
    dll.head->next->next->next = new node(2);
    dll.head->next->next->next->prev = dll.head->next->next;

    cout << "Original List: "<<endl;
    displayLL(dll.head);

    cout<<endl;


    removeDuplicates(dll.head); 

    cout << "List after removing duplicates: "<<endl;;
    displayLL(dll.head);
 
 return 0;
}

