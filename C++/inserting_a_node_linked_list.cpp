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
    struct node *p,*p1;
     cin>>value;
     p1=new node;
    p1->data=value;
    p1->next=NULL;
    if(head==NULL)
    head=p1;
    else 
    {
    p=head;
    while(p->next!=NULL)
    {
      p=p->next;
    }
  p->next=p1;
    }
}
void display()
{
 
   struct node *p3;
   p3=head;
   cout<<"Linked List:";
   while(p3!=NULL)
   {
    cout<<"->"<<p3->data;
    p3=p3->next;
   }

}
int main()
{
    int n,m,p,count=0;
    cin>>n;
    m=n;
    p=m;
    struct node *p6,*p7,*ne;
    
    
    while(n--)
    {
      create();
    }
    int key,data;
    cin>>key;
    cin>>data;

 p7=head;
 

 while(p7->data!=key)
 {
     p6=p7;
     p7=p7->next;
     count++;
        if(count==m)
        {
            break;
        }
 }

cout<<count<<m;

if(count>=m)
{ 
  
  cout<<"Node not found"<<endl;
  
}

else
{
 ne=new node;
 p6->next=ne;
 ne->data=data;
 ne->next=p7;
 
}

 display();
 





 
  return 0;  

}