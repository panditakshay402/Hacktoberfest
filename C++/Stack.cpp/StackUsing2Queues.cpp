/*

Pushing Elements:
When we push elements 1, 2, 3, and 4 onto the stack:
The push method adds each element to q1.
State of q1 after each push:
After pushing 1: q1 = [1]
After pushing 2: q1 = [1, 2]
After pushing 3: q1 = [1, 2, 3]
After pushing 4: q1 = [1, 2, 3, 4]
q2 remains empty throughout this process: q2 = [].

Popping an Element:
When we call the Pop method:
The method transfers elements from q1 to q2 until q1 is empty.
During this process, the last element added (the topmost of the stack) is 4, which is the last element to be dequeued from q1.
State during popping:
Transfer from q1 to q2:
Dequeue 1: q1 = [2, 3, 4], q2 = [1]
Dequeue 2: q1 = [3, 4], q2 = [1, 2]
Dequeue 3: q1 = [4], q2 = [1, 2, 3]
Dequeue 4: q1 = [], q2 = [1, 2, 3] (At this point, 4 is the popped element.)
After popping, elements are transferred back from q2 to q1:
Enqueue 1: q1 = [1], q2 = [2, 3]
Enqueue 2: q1 = [1, 2], q2 = [3]
Enqueue 3: q1 = [1, 2, 3], q2 = []
Final state after popping 4: q1 = [1, 2, 3], q2 = [].
Peeking the Top Element:

When we call the Peek method:
Similar to the pop operation, elements are transferred from q1 to q2 until q1 is empty.
The last element dequeued will be the current top of the stack (3).
State during peeking:
Transfer:
Dequeue 1: q1 = [2, 3], q2 = [1]
Dequeue 2: q1 = [3], q2 = [1, 2]
Dequeue 3: q1 = [], q2 = [1, 2, 3] (Here, 3 is the top element.)
After displaying 3, elements are transferred back to q1:
Enqueue 1: q1 = [1], q2 = [2]
Enqueue 2: q1 = [1, 2], q2 = []
Final state after peeking: q1 = [1, 2], q2 = [].
Checking if Stack is Empty:

The Empty method checks if q1 is empty:
Since q1 contains elements [1, 2], the method will return False, indicating that the stack is not empty.
*/
#include<iostream>
using namespace std;
class queue{
    int f=0,r=-1,items[100];
    public:
    int isEmpty(){
        if(f>r)
        return 1;
        else return 0;
    }
    int isFull(){
        if(r==99)
        return 1;
        else return 0;
    }
    void insert(int x){
       if(isFull()){
           cout<<"queue full, cant insert";
           exit(1);
       }
       items[++r]=x;
    }
    int delete1(){
        if(isEmpty()){
            cout<<"queue empty";
            exit(1);
        }
        return(items[f++]);
    }
    void show(){
        cout<<"Queue from start is:";
        for(int i=f;i<=r;i++){
            cout<<items[i]<<" ";
        }cout<<endl;
    }
};
class stack{
    int x;
    queue q1,q2;
    public:
    void push(int x){
        q1.insert(x);
    }
    void Pop(){
        while(!q1.isEmpty()){
            x=q1.delete1();
            if(q1.isEmpty())
            {cout<<x<<endl;
            break;
            }
            q2.insert(x);
        }
        while(!q2.isEmpty()){
                q1.insert(q2.delete1());
            }
    }
    void Empty(){
        if(q1.isEmpty())
        cout<<"True";
        else 
        cout<<"False";
    }
    void Peek(){
        while(!q1.isEmpty()){
            x=q1.delete1();
            if(q1.isEmpty())
            cout<<x<<endl;
            q2.insert(x);
        }
        while(!q2.isEmpty()){
                q1.insert(q2.delete1());
            }

    }
};
int main(){
    int x,n;
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<"Popping topmost element:";
    s.Pop();
    cout<<"Now the stacktop is:";
    s.Peek();
    cout<<"Checking if the stack is empty:";
    s.Empty();
    
    return 0;
}
