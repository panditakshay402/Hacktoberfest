#include<iostream>
using namespace std;

struct node{
  int data;                 //for storing data into linkedlist
  struct node *next;
}
struct node *head = NULL;
struct node *p,*q,*k,*temp; //temporary pointers 

void creation(int x){
  p = (struct node*)malloc(sizeof(struct node));
  p->data = x;
  p->next = NULL;
  if(head == NULL){
        p = head;
  }
  else{
        temp = head;
        while(temp->next != NULL){
              temp = temp -> next;
        }
        temp->next = p;
    }
}


void display(){
  temp = head;
  while(temp->next != NULL){
        cout << temp->data << " ";
  }
  cout << temp->data << endl;
}


// Insertion at beginning 
void insbeg(struct node *q){
    q->next = head;
    head = q;
}


// Insertion at end
void insend(struct node *q){
    temp = head;
    while(temp->next != NULL){
          temp = temp->next;
    }
    temp->next = q;
}


// Insertion at specific position
void inspos(struct node *q){
    int position;
    cout << "Enter Position to be inserted: ";
    cin >> position;
    int i = 1;
    p = head;
    while(i < pos){
        k = p;
        p = p->next;
        i++;
    }
    k->next = q;
    q->next = p;
}

// INSERTION FUNCTION 
void insertion(int d){
  cout << "Enter: " << "1.insert begin\n 2.insert end\n 3.insert at specific position\n";
  int choice;
  cin >> choice;
  q = (struct node*)malloc(sizeof(struct node));
  q->data = d;
  q->next = NULL;
  switch(choice){
case 1: insbeg(q);
  break;
case 2: insend(q);
  break;
case 3: inspos(q);
  break;
  }
}


// Deletion at beginning
void delbeg(){
  p = head;
  head = head->next;
  cout << p->data << " is deleted" << endl;
  free(p);
}

// Deletion at end
void delend(){
  if(head->next == NULL){
      cout << head->data << " is deleted" << endl;
      head = NULL;
  }
else{
      p = head;
      while(p->next != NULL){
          k = p;
          p = p->next;
      }
    k->next = NULL;
    cout << p->data << " is deleted" << endl;
    free(p);
    }
}


// Deletion at specific position
void delpos(){
  int position;
  cout << "Enter Position to be deleted: ";
  cin >> position;
  int i=1;
  p = head;
  while(i <= pos){
        k = p;
        p = p->next;
        i++;
  }
k->next = p->next;
cout << p->data << " is deleted" << endl;
free(p);
}

// DELETION FUNCTION

void deletion(){
  cout << "Enter : " << "1.delete at begin\n 2.delete at end\n 3.delete at specific position:  ";
  int choice;
  cin >> choice;
  switch(choice){
case 1: delbeg();
  break;
case 2: delend();
  break;
case 3: delpos();
  break;
  }
}


// MAIN FUNCTION

int main(){
  creation(10);
  creation(20);
  creation(30);

  display();

  char ch;
  cout << "Enter Y or N for insertion: ";
  cin >> ch;
  while(ch == 'y' || ch == 'Y'){
        int d;
        cout << "Enter data to be inserted: ";
        cin >> d;
        insertion(d);
        display();
        cout << endl;

        cout << "Enter Y or N for insertion: ";
        cin >> ch;
  }

cout << "Enter Y or N for deletion: ";
cin >> ch;
while(ch == 'Y' || ch == 'y'){
      deletion();
      display();
      cout << endl;
      cout << "Enter Y or N for deletion: ";
      cin >> ch;
}

    return 0;
}
        

    
