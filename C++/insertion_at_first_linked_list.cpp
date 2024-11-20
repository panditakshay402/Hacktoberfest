//INSERTION AT BEGINNING OF LINKED LIST
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*head=NULL;

void create()
{
   int value;
   cin>>value;
   struct node *p,*p1;
   p1=new node;
        p1->data=value;
        p1->next=NULL;
        if(head==NULL)
        head=p1;
        else
        {
          p=head;
          p1->next=p;
          head=p1;
        

        }


}
void display()
{

       struct node *p2;
        p2=head;
        while(p2!=0)
        {
            cout<<p2->data<<" ";
            p2=p2->next;
        }

}
int main() 
{
    struct node *p,*p1,*p2;
    int n;
    cin>>n;
   
    while(n--)
    {
        create();
    }
      
       display();
       return 0; 

    
}